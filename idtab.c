/* Identifier table handling */

#include <stdio.h>
#include "common.h"

#define MODULO  255
#define NAMEMAX 200
#define CHARMAX 5000


char *entername(char *id, int flag);


typedef struct CHAIN_x 
	{ char *name; IDPROP val; struct CHAIN_x *next; } CHAIN;
typedef CHAIN *HASHTBL[MODULO];

static HASHTBL global,local;

static int nametop = 0;
static int namesave;
static CHAIN nameheap[NAMEMAX];
static int chartop = 0;
static int charbtm = CHARMAX;
static char charheap[CHARMAX];
extern int typetop;
static int typesave;
static int localmode = 0;
		/* 0: global variable
		   1: local variable
		   2: formal parameter */

int lcglobal = 0;
static int lclocal;
extern int pc;
extern codetype code[CODEMAX];
extern int errcnt;
extern TYPE inttype;

enter(id,typ)
char *id;
TYPE *typ;
{	int i,sz;
	CHAIN *p;
	CHAIN **slot;
	extern char *entername();

	i=hash(id);
	if (localmode)
		slot=(&local[i]);
	else
		slot=(&global[i]);
	p=(*slot);
	while (p!=0) {
		if (strcompare(id,p->name)==0) {
			yyerror("double definition");
			return;
		}
		p=p->next;
	}
	if (nametop>=NAMEMAX)
		fatal("name table overflow");
	nameheap[nametop].name=entername(id,localmode);
	nameheap[nametop].val.t=typ;
	sz=(typ->size+sizeof(int)-1)/sizeof(int)*sizeof(int);
	if (sz<=0)
		yyerror("variable of size 0");
	if (localmode) {
		nameheap[nametop].val.base=1;
		if (localmode==2) {
			nameheap[nametop].val.offset=lclocal;
			lclocal+=sz;
		}
		else {
			lclocal-=sz;
			nameheap[nametop].val.offset=lclocal;
		}
	}
	else {
		nameheap[nametop].val.base=0;
		nameheap[nametop].val.offset=lcglobal;
		lcglobal+=sz;
	}
	nameheap[nametop].next=(*slot);
	*slot=(&nameheap[nametop++]);
}

IDPROP *lookup(id)
char *id;
{	IDPROP *p;
	extern IDPROP *idsearch();

	p=idsearch(id);
	if (p!=NIL)
		return(p);
	yyerror("undefined identifier");
	enter(id,&inttype);
	p=idsearch(id);
	if (p==NIL)
		fatal("system error: lookup");
	return(p);
}

IDPROP *idsearch(char *id)
{
	int i;
	CHAIN *p;

	i=hash(id);
	if (localmode) {
		p=local[i];
		while (p!=0) {
			if (strcompare(id,p->name)==0)
				return(&p->val);
			p=p->next;
		}
	}
	p=global[i];
	while (p!=0) {
		if (strcompare(id,p->name)==0)
			return(&p->val);
		p=p->next;
	}
	return(NIL);
}

int hash(char *id)
{
	int v;

	v=0;
	while (*id)
		v=255*v+(*id++);
	if (v<0)
		v=(-v);
	return(v%MODULO);
}

#define FUNCMAX 256
static int functop = 0;
int currfunc;
static struct { char *name; int pos,localsize; } function[FUNCMAX];

enterfunc(id)
char *id;
{	int i;

	currfunc=reffunc(id);
	if (function[currfunc].pos>=0)
		yyerror("function double definition");
	function[currfunc].pos=pc;
	localmode=2;
	namesave=nametop;
	typesave=typetop;
	lclocal=2*sizeof(int);          /* size of save area */
	for (i=0; i<MODULO; i++)
		local[i]=NIL;
	emit(FUNCENT,currfunc,0);
}

endparam()
{
	localmode=1;
	lclocal=0;
}

endfunc()
{
	localmode=0;
	nametop=namesave;
	typetop=typesave;
	chartop=0;
	function[currfunc].localsize=lclocal;
	emit(LOADCONST,0,0);
	emit(FUNCRET,currfunc,0);
}

int reffunc(id)
char *id;
{	int i;

	if (idsearch(id)!=NIL)
		yyerror("conflict between function and variable");
	for (i=0; i<functop; i++)
		if (strcompare(id,function[i].name)==0) 
			return(i);
	if (functop>=FUNCMAX)
		fatal("too many functions");
	function[functop].name=entername(id,0);
	function[functop].pos=(-1);
	return(functop++);
}

checkfunc()
{	int i;

	if (functop<=0) {
		yyerror("no executable code");
		return;
	}
	for (i=0; i<functop; i++)
		if (function[i].pos<0) 
			linkstdfunc(i);
		/* replace function number by code-position/local-size */
	for (i=0; i<pc; i++)
		switch (code[i].op) {
		case CALL:
			if (code[i].f1>=0)
				code[i].f1=function[code[i].f1].pos;
			break;
		case FUNCENT:
		case FUNCRET:
			code[i].f1=function[code[i].f1].localsize;
			break;
		default:
			break;
		}
}

#define STDCNT  3

int linkstdfunc(int i)
{
	static struct { char *stdname; int scode; } standard[STDCNT] =
		{ "getchar",-1,
		  "putchar",-2, 
		  "printf", -3 };
	int j;

	for (j=0; j<STDCNT; j++)
		if (strcompare(function[i].name,standard[j].stdname)==0) {
			function[i].pos=standard[j].scode;
			break;
		}
	if (j>=STDCNT) {
		printf("undefined function: %s\n",function[i].name);
		errcnt++;
	}
}

char *entername(char *id, int flag)
{	char *cp;
	int i,j,l,result;

	cp=id;
	l=0;
	while (*cp++)
		l++;
	l++;
	if (charbtm-chartop<l)
		fatal("identifier character buffer overflow");
	if (flag) {
		result=chartop;
		j=chartop;
		chartop+=l;
	}
	else {
		charbtm-=l;
		result=charbtm;
		j=charbtm;
	}
	cp=id;
	for (i=0; i<l; i++) 
		charheap[j++]=(*cp++);
	return(&charheap[result]);
}

int strcompare(a,b)
char *a,*b;
{
	while (*a==*b) {
		if (*a==0)
			return(0);
		a++;
		b++;
	}
	if (*a<*b)
		return(-1);
	else
		return(1);
}
