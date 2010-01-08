/* Expression-tree and Type-list handling */

#include <stdio.h>
#include "common.h"

#define TREEMAX 100

static int treetop = 0;
static TREE tree[TREEMAX];

cleartree()
{
	treetop=0;
}

TREE *maketree(a,b,c)
int a;
TREE *b,*c;
{
	if (treetop>=TREEMAX) 
		fatal("too complex expression");
	tree[treetop].val=a;
	tree[treetop].left=b;
	tree[treetop].right=c;
	return(&tree[treetop++]);
}

int eval(x)
TREE *x;
{
	switch (x->val) {
	case T_ID:
		yyerror("identifier is not allowed in constant expression");
		return(0);
	case T_LIT:
		return((int)(x->left));
	case INVSIGN:
		return(-eval(x->left));
	case NOT:
		return(!eval(x->left));
	case ONECMPL:
		return(~eval(x->left));
	case DEREF:
	case ADRS:
	case PREINCR:
	case PREDECR:
	case PSTINCR:
	case PSTDECR:
		yyerror("unallowed operator in constant expression");
		return(0);
	case MULT:
		return(eval(x->left)*eval(x->right));
	case DIV:
		return(eval(x->left)/eval(x->right));
	case MOD:
		return(eval(x->left)%eval(x->right));
	case ADD:
		return(eval(x->left)+eval(x->right));
	case SUB:
		return(eval(x->left)-eval(x->right));
	case LSFTOP:
		return(eval(x->left)<<eval(x->right));
	case RSFTOP:
		return(eval(x->left)>>eval(x->right));
	case LTOP:
		return(eval(x->left)<eval(x->right));
	case LEOP:
		return(eval(x->left)<=eval(x->right));
	case EQOP:
		return(eval(x->left)==eval(x->right));
	case NEOP:
		return(eval(x->left)!=eval(x->right));
	case ANDOP:
		return(eval(x->left)&eval(x->right));
	case XOROP:
		return(eval(x->left)^eval(x->right));
	case OROP:
		return(eval(x->left)|eval(x->right));
	case LANDOP:
		return(eval(x->left)&&eval(x->right));
	case LOROP:
		return(eval(x->left)||eval(x->right));
	case ASSIGN:
		yyerror("assignment is not allowed in constant expression");
		return(0);
	case CALL:
		yyerror("function call is not allowed in constant expression");
		return(0);
	default:
		fatal("system error: eval");
	}
}

int printtree(TREE *x)                    /* for debug */
{
	if (x==NIL)
		printf("NIL\n");
	else
		subtree(x,0);
}

int subtree(TREE *x, int indent)        /* for debug */
{
	if (x!=NIL) {
		if (x->val==T_ID || x->val==T_LIT || x->val==CALL) {
			skip(indent+1);
			printf("%5d\n",x->left);
		}
		else
			subtree(x->left,indent+1);
		skip(indent);
		printf("%5d\n",x->val);
		subtree(x->right,indent+1);
	}
}

int skip(int n)                  /* for debug */
{
	while (n-->0)
		printf("     ");
}


#define TYPEMAX 256
int typetop = 0;
static TYPE typeheap[TYPEMAX];

TYPE inttype = { '-',sizeof(int),0 };
TYPE chartype = { '-',sizeof(char),0 };

TYPE *newtype(int ds, int sz, TYPE *nx)
{
	if (typetop>=TYPEMAX)
		fatal("too many types");
	typeheap[typetop].kind=ds;
	typeheap[typetop].size=sz;
	typeheap[typetop].next=nx;
	return(&typeheap[typetop++]);
}

TYPE *reverse(t,base)
TYPE *t,*base;
{	TYPE *p,*q;

	p=base;
	while (t!=NIL) {
		if (p->size<=0)
			yyerror("invalid array size");
		switch (t->kind) {
		case '*':
			t->size=sizeof(int);
			break;
		case '[':
			t->size=t->size*p->size;
			break;
		default:
			fatal("system error: reverse");
		}
		q=t->next;
		t->next=p;
		p=t;
		t=q;
	}
	return(p);
}

printtype(t)                    /* for debug */
TYPE *t;
{
	if (t==NIL)
		printf("NIL");
	else 
		for (;;) {
			printf("(%c %d)",t->kind,t->size);
			t=t->next;
			if (t==NIL)
				break;
			printf("->");
		}
	putchar('\n');
}
