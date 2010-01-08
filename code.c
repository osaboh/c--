/* Code generator for a virtual stack machine */

#include <stdio.h>
#include "common.h"

int pc;
codetype code[CODEMAX];

extern TYPE inttype;

/* "compile" generates code for an expression "x".  "goal" operand
   is one of LOAD, POPUP, FJUMP, TJUMP.
       LOAD  -> The value of the expression should be placed on stack.
       POPUP -> The value is not used.  Only its side effect is
                important.
       FJUMP -> If the value of the expression is false, jumps to a
                certain location.  If true, execution continues at the
                next instruction.
       TJUMP -> Opposite of FJUMP.
   In case of FJUMP or TJUMP, "compile" returns a chain of jumps to be
   filled in later.  */


//	extern TYPE *rvalue();
//	extern TYPE *newtype(),*lvalue(),*address(),*loadstore();


extern TYPE *newtype(int ds, int sz, TYPE *nx);
TYPE *rvalue(TREE *x);
TYPE *lvalue(TREE *x);
TYPE *address(TREE *x);
TYPE *loadstore(int op, TYPE *tp);


int compile(TREE *x, int goal)
{
	int l,r;

	switch (goal) {
	case LOAD:
		rvalue(x);
		return(0);
	case POPUP:
		rvalue(x);
		emit(POPUP,0,0);
		return(0);
	case FJUMP:
	case TJUMP:
		if (x->val!=LANDOP && x->val!=LOROP) {
			rvalue(x);
			emit(goal,0,0);
			return(pc-1);
		}
		if (x->val==LANDOP) {
			l=compile(x->left,FJUMP);
			if (goal==FJUMP) {
				r=compile(x->right,FJUMP);
				return(concat(l,r));
			}
			else {
				r=compile(x->right,TJUMP);
				filljump(l);
				return(r);
			}
		}
		else {
			l=compile(x->left,TJUMP);
			if (goal==TJUMP) {
				r=compile(x->right,TJUMP);
				return(concat(l,r));
			}
			else {
				r=compile(x->right,FJUMP);
				filljump(l);
				return(r);
			}
		}
	}
	return 0;
}

TYPE *rvalue(TREE *x)            /* place value at top of stack */
{
	int n;
	TYPE *tp,*l,*r;

	switch (x->val) {
	case T_ID:
	case DEREF:
		tp=address(x);
		if (tp==NIL)
			return(NIL);
		if (tp->kind=='[')
			return(newtype('*',sizeof(int),tp->next));
		return(loadstore(LOAD,tp));
	case T_LIT:
		emit(LOADCONST,(int)x->left,0);
		return(&inttype);
	case ADRS:
		tp=lvalue(x->left);
		if (tp==NIL)
			return(NIL);
		return(newtype('*',sizeof(int),tp));
	case INVSIGN:
	case NOT:
	case ONECMPL:
		tp=rvalue(x->left);
		if (tp==NIL)
			return(NIL);
		emit(x->val,0,0);
		return(&inttype);
	case PREINCR:
	case PREDECR:
	case PSTINCR:
	case PSTDECR:
		tp=lvalue(x->left);
		if (tp==NIL)
			return(NIL);
		if (tp->kind=='*')
			n=tp->next->size;
		else
			n=1;
		emit(COPYVAL,0,0);
		loadstore(LOAD,tp);
		if (x->val==PSTINCR || x->val==PSTDECR) {
			emit(EXCHANGE,0,0);
			emit(COPYVAL,sizeof(int),0);
		}
		emit(LOADCONST,n,0);
		if (x->val==PREINCR || x->val==PSTINCR)
			emit(ADD,0,0);
		else
			emit(SUB,0,0);
		loadstore(ASSIGN,tp);
		if (x->val==PSTINCR || x->val==PSTDECR)
			emit(POPUP,0,0);
		return(tp);
	case MULT:
	case DIV:
	case MOD:
	case LSFTOP:
	case RSFTOP:
	case LTOP:
	case LEOP:
	case EQOP:
	case NEOP:
	case ANDOP:
	case XOROP:
	case OROP:
		l=rvalue(x->left);
		r=rvalue(x->right);
		if (l==NIL || r==NIL)
			return(NIL);
		emit(x->val,0,0);
		return(&inttype);
	case ADD:
	case SUB:
		l=rvalue(x->left);
		r=rvalue(x->right);
		if (l==NIL || r==NIL)
			return(NIL);
		if (l->kind=='*' && r->kind=='*') {
			if (x->val==ADD) {
				yyerror("invalid type");
				return(NIL);
			}
			else {
				emit(SUB,0,0);
				emit(LOADCONST,l->next->size,0);
				emit(DIV,0,0);
			}
			return(&inttype);
		}
		if (l->kind=='*') {
			emit(LOADCONST,l->next->size,0);
			emit(MULT,0,0);
			emit(x->val,0,0);
			return(l);
		}
		if (r->kind=='*') {
			if (x->val==SUB) {
				yyerror("invalid type");
				return(NIL);
			}
			else {
				emit(EXCHANGE,0,0);
				emit(LOADCONST,r->next->size,0);
				emit(MULT,0,0);
				emit(ADD,0,0);
			}
			return(r);
		}
		emit(x->val,0,0);
		return(&inttype);
	case LANDOP:
	case LOROP:
		n=compile(x,FJUMP);
		emit(LOADCONST,1,0);
		emit(JUMP,pc+2,0);
		filljump(n);
		emit(LOADCONST,0,0);
		return(&inttype);
	case ASSIGN:
		l=lvalue(x->left);
		r=rvalue(x->right);
		if (l==NIL || r==NIL)
			return(NIL);
		return(loadstore(ASSIGN,l));
	case CALL:
		n=arguments(x->right);
		emit(CALL,(int)x->left,n*sizeof(int));
		return(&inttype);
	default:
		fatal("system error: rvalue");
	}
	return NULL;
}

int arguments(TREE *x)	/* arguments are evaluated from right to left */
{
	if (x==NIL)
		return(0);
	rvalue(x->left);
	return(arguments(x->right)+1);
}

TYPE *lvalue(TREE *x)            /* place address at top of stack */
{
	TYPE *tp;

	switch (x->val) {
	case T_ID:
	case DEREF:
		tp=address(x);
		if (tp==NIL)
			return(NIL);
		if (tp->kind=='[') {
			yyerror("array name is not an lvalue");
			return(NIL);
		}
		return(tp);
	case T_LIT:
		yyerror("constant is not an lvalue");
		return(NIL);
	case ADRS:
	case INVSIGN:
	case NOT:
	case ONECMPL:
	case PREINCR:
	case PREDECR:
	case PSTINCR:
	case PSTDECR:
	case MULT:
	case DIV:
	case MOD:
	case ADD:
	case SUB:
	case LSFTOP:
	case RSFTOP:
	case LTOP:
	case LEOP:
	case EQOP:
	case NEOP:
	case ANDOP:
	case XOROP:
	case OROP:
	case LANDOP:
	case LOROP:
	case ASSIGN:
		yyerror("invalid operator in lvalue");
		return(NIL);
	case CALL:
		yyerror("function call is not an lvalue");
		return(NIL);
	default:
		fatal("system error: lvalue");
	}
	return NULL;
}

TYPE *address(TREE *x)
{
	IDPROP *idp;
	TYPE *tp;

	switch (x->val) {
	case T_ID:
		idp=(IDPROP *)x->left;
		if (idp==NIL)
			return(NIL);
		emit(LOADADRS,idp->base,idp->offset);
		return(idp->t);
	case DEREF:
		tp=rvalue(x->left);
		if (tp==NIL)
			return(NIL);
		if (tp->kind!='*') {
			yyerror("illegal indirection");
			return(NIL);
		}
		return(tp->next);
	default:
		fatal("system error: address");
	}
	return NULL;
}

TYPE *loadstore(int op, TYPE *tp)
{
	if (tp->size==sizeof(char))
		emit(op,sizeof(char),0);
	else if (tp->size==sizeof(int))
		emit(op,sizeof(int),0);
	else {
		yyerror("system error: invalid type for loadstore");
		return(NIL);
	}
	return(tp);
}


#define NESTMAX 15
static int depth;
static struct { int elslink,brklink,loophed,stat; } ststack[NESTMAX];

	/* elslink: chain of jumps to else part (IF only)
	   loophed: address of loop head (WHILE only)
	   brklink: chain of jumps exitting from the statement */

#define IFSTAT  1
#define LOOP    2

void initcode(void)
{
	pc=0;
	depth=0;
	emit(CALL,0,0);         /* first function is main program */
	emit(STOP,0,0);
}

void if1(int link)
{
	if (depth>=NESTMAX)
		fatal("too deep statement nesting");
	ststack[depth].elslink=link;
	ststack[depth].stat=IFSTAT;
	depth++;
}

void if2(void )
{
	emptycheck(IFSTAT);
	ststack[depth-1].brklink=pc;
	emit(JUMP,0,0);
	filljump(ststack[depth-1].elslink);
}

void if3(void)
{
	emptycheck(IFSTAT);
	filljump(ststack[depth-1].brklink);
	depth--;
}

void while1(void)
{
	if (depth>=NESTMAX)
		fatal("too deep statement nesting");
	ststack[depth].loophed=pc;
	ststack[depth].stat=LOOP;
	depth++;
}

void while2(int link)
{
	emptycheck(LOOP);
	ststack[depth-1].brklink=link;
}

void while3(void )
{
	emptycheck(LOOP);
	emit(JUMP,ststack[depth-1].loophed,0);
	filljump(ststack[depth-1].brklink);
	depth--;
}

void break1(void)
{
	int d;
	d=depth;
	while (d>0 && ststack[d-1].stat!=LOOP)
		d--;
	if (d<=0)
		yyerror("break statement outside loop");
	else {
		emit(JUMP,ststack[d-1].brklink,0);
		ststack[d-1].brklink=pc-1;
	}
}

void emptycheck(int st)
{
	if (depth<=0)
		fatal("system error: empty statement stack");
	if (ststack[depth-1].stat!=st)
		yyerror("invalid statement nesting");
}

void filljump(int link)
{
	int i,j;

	i=link;
	while (i) {
		j=code[i].f1;
		code[i].f1=pc;
		i=j;
	}
}

int concat(int l, int r)            /* concatenation of jump chains */
{	int i,j;

	i=l;
	j=0;
	while (i) {
		j=i;
		i=code[i].f1;
	}
	if (j==0)
		return(r);
	else {
		code[j].f1=r;
		return(l);
	}
}

void emit(int op, int f1, int f2)
{
	if (pc>=CODEMAX)
		fatal("too large code");
	code[pc].op=op;
	code[pc].f1=f1;
	code[pc].f2=f2;
	pc++;
}

void printcode(void)                     /* for debug */
{
	int i;

	for (i=0; i<pc; i++) {
		printf("%5d %4d %8d %8d\n",
		       i,code[i].op,code[i].f1,code[i].f2);
	}
}
