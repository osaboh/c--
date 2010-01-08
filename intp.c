/* Virtual machine interpreter */

#include <stdio.h>
#include <stdlib.h>
#include "common.h"

#define STKSIZE 40000
static int workspace[STKSIZE/(sizeof(int)/sizeof(char))];

static char *stack = (char *)workspace;
static int sp,fp,ic;
extern int lcglobal;
extern codetype code[CODEMAX];

interpret(trace)
int trace;
{	int w1,w2,val;
	char *adrs;

	ic=0;
	sp=STKSIZE;
	for (;;) {
		if (trace) {
			printf("ic=%4d, sp=%5d, fp=%5d, ",ic,sp,fp);
			printf("code=(%4d,%4d,%4d), top=%10d\n",
			       code[ic].op,code[ic].f1,code[ic].f2,
			       top(0));
		}
		switch (code[ic].op) {
		case LOAD:
			if (code[ic].f1==sizeof(char))
				push(*((char *)pop()));
			else
				push(*((int *)pop()));
			break;
		case LOADADRS:
			if (code[ic].f1==0)
				push((int)(stack+code[ic].f2));
			else
				push((int)(stack+(fp+code[ic].f2)));
			break;
		case LOADCONST:
			push(code[ic].f1);
			break;
		case EXCHANGE:
			w2=pop();
			w1=pop();
			push(w2);
			push(w1);
			break;
		case POPUP:
			pop();
			break;
		case CALL:
			if (code[ic].f1<0) {
				standard();
				break;
			}
			else {
				push(ic);
				push(fp);
				ic=code[ic].f1;
				continue;
			}
		case FUNCENT:
			fp=sp;
			sp+=code[ic].f1;
			if (sp<lcglobal)
				runerror("stack overflow");
			break;
		case FUNCRET:
			restore(1);
			break;
		case JUMP:
			ic=code[ic].f1;
			continue;
		case FJUMP:
			if (pop())
				break;
			ic=code[ic].f1;
			continue;
		case TJUMP:
			if (!pop())
				break;
			ic=code[ic].f1;
			continue;
		case COPYVAL:
			push(top(code[ic].f1));
			break;
		case STOP:
			if (sp!=STKSIZE-sizeof(int))
				runerror("illegal termination");
			return;
		case INVSIGN:
			push(-pop());
			break;
		case NOT:
			push(!pop());
			break;
		case ONECMPL:
			push(~pop());
			break;
		case MULT:
			push(pop()*pop());
			break;
		case DIV:
			w2=pop();
			w1=pop();
			push(w1/w2);
			break;
		case MOD:
			w2=pop();
			w1=pop();
			push(w1%w2);
			break;
		case ADD:
			push(pop()+pop());
			break;
		case SUB:
			w2=pop();
			w1=pop();
			push(w1-w2);
			break;
		case LSFTOP:
			w2=pop();
			w1=pop();
			push(w1<<w2);
			break;
		case RSFTOP:
			w2=pop();
			w1=pop();
			push(w1>>w2);
			break;
		case LTOP:
			w2=pop();
			w1=pop();
			push(w1<w2);
			break;
		case LEOP:
			w2=pop();
			w1=pop();
			push(w1<=w2);
			break;
		case EQOP:
			push(pop()==pop());
			break;
		case NEOP:
			push(pop()!=pop());
			break;
		case ANDOP:
			push(pop()&pop());
			break;
		case XOROP:
			push(pop()^pop());
			break;
		case OROP:
			push(pop()|pop());
			break;
		case ASSIGN:
			val=pop();
			adrs=(char *)pop();
			if (adrs<stack || adrs>=(stack+STKSIZE))
				runerror("assigning out of memory space");
			if (code[ic].f1==sizeof(char))
				*((char *)adrs)=val;
			else
				*((int *)adrs)=val;
			push(val);
			break;
		default:
			printf("undefined op code: %d\n",code[ic].op);
			runerror("system error: interpret");
		}
		ic++;
	}
}

int standard(void)
{
	int n,i,p[10];

	switch (code[ic].f1) {
	case -1:
		push(getchar());
		restore(0);
		break;
	case -2:
		putchar(top(0));
		push(0);
		restore(0);
		break;
	case -3:
		n=code[ic].f2;
		if(n>10*sizeof(int))
			runerror("too many arguments for printf");
		for (i=0; sizeof(int)*i<n; i++)
			p[i]=pop();
		printf((char *)p[0],p[1],p[2],p[3],p[4],
		       p[5],p[6],p[7],p[8],p[9]);
		push(0);
		break;
	default:
		runerror("system error: standard function");
	}
}

int restore(int s)
{	int x;

	x=pop();                        /* function result */
	if (s) {
		sp-=code[ic].f1;        /* release local frame, f1<=0 */
		fp=pop();
		ic=pop();
	}
	sp+=code[ic].f2;                /* release actual parameters */
	if (sp>STKSIZE)
		runerror("system error: over popup");
	push(x);
}

int push(int x)
{
	if (sp<=lcglobal)
		runerror("stack overflow");
	sp-=sizeof(int);
	*((int *)&stack[sp])=x;
}

int pop(void)
{
	int x;

	if (sp>=STKSIZE)
		runerror("stack underflow");
	x=(*((int *)&stack[sp]));
	sp+=sizeof(int);
	return(x);
}

int top(int offset)
{
	return(*((int *)(&stack[sp]+offset)));
}

runerror(char *s)
{
	printf("%s\n",s);
	exit(1);
}


/*  run time memory organization

                        low address
              -------------------------------
             |                               |
             |        global variables       |
             |                               |
  lcglobal-> |-------------------------------|
             |                               |
             |           free space          |
             |                               |
        sp-> |-------------------------------|  +
             |        evaluation stack       |  |
             |        local variables        |  |
        fp-> |-------------------------------|  | current function frame
             |       register save area      |  |
             |       function arguments      |  |
             |-------------------------------|  +
             |                               |
             |    previous function frames   |
             |                               |
              -------------------------------
                        high address
*/
