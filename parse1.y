/* Grammar definitions and lexical analyzer */


%{
#include <stdio.h>
#include <stdlib.h>
#include "common.h"

#define NRES    27
#define IDSIZE  8
#define STRSIZE 2000
#define NEGL    -1

extern FILE *source;

static int c = ' ';
static int line = 1;
static int tokenline;
static char id[IDSIZE+1],declid[IDSIZE+1];
static char string[STRSIZE];
static int strtop = 0;
static int value;

static TYPE *ctype,*basetype;
extern TYPE inttype,chartype;
extern int currfunc;
extern int errcnt;

extern TYPE *newtype(),*reverse();
extern TREE *maketree();
extern IDPROP *lookup();

typedef TREE *T;
%}





%start  program

%token  IDENT LITERAL;
%token  COMMA SEMICOLON;
%token  LBRACE RBRACE LPAR RPAR LBRACK RBRACK;
%token  TYPENAME;
%token  BREAK ELSE IF RETURN WHILE;

/* operators, in the order of increasing precedence */

%right  EQUAL;
%left   OROR;
%left   ANDAND;
%left   OR;
%left   UPARROW;
%left   AND;
%binary EQEQ NOTEQ;
%binary LE LT GE GT;
%left   LSHIFT RSHIFT;
%left   PLUS MINUS;
%left   STAR SLASH PERCENT;
%right  PLUSPLUS MINUSMINUS EXCLAM TILDE;
%left   LBRACK;



%%


/* declarations */

program
		:	{ initcode(); }
		  ext_def_list
			{ checkfunc(); }
		;

ext_def_list
		: ext_def_list external_def
		| /* empty */
		;

external_def
		: var_decl
		| function
		| error SEMICOLON
		;

function
		: IDENT 
			{ enterfunc(id); } 
		  LPAR formal_params RPAR
			{ endparam(); }
		  LBRACE local_decl_list statement_list RBRACE
			{ endfunc(); }
		;

local_decl_list
		: local_decl_list var_decl
		| /* empty */
		;

var_decl
		: TYPENAME declarator_list SEMICOLON
		;

declarator_list
		: declarator_list COMMA declaration
		| declaration
		;

declaration
		:	{ ctype=NIL; cleartree(); }
		  declarator
			{ enter(declid,reverse(ctype,basetype)); }
		;

declarator
		: IDENT
			{ copystr(declid,id); }
		| LPAR declarator RPAR
		| STAR declarator
			{ ctype=newtype('*',0,ctype); }
		| declarator LBRACK opt_expression RBRACK
			{ ctype=newtype('[',eval((T)$3),ctype); }
		;

formal_params
		: formal_list
		| /* empty */
		;

formal_list
		: formal_list COMMA formal
		| formal
		;

formal
		: IDENT
			{ enter(id,&inttype); }
		;

/* statements */

statement_list
		: statement_list statement
		| /* empty */
		;

statement
		: SEMICOLON
		|	{ cleartree(); }
		  expression SEMICOLON
			{ compile((T)$2,POPUP); }
		| LBRACE statement_list RBRACE
		| IF
			{ cleartree(); }
		  LPAR expression RPAR
			{ if1(compile((T)$4,FJUMP));}
		  statement
			{ if2(); }
		  if_tail
			{ if3(); }
		| WHILE
			{ while1(); cleartree(); }
		  LPAR expression RPAR
			{ while2(compile((T)$4,FJUMP)); }
		  statement
			{ while3(); }
		| BREAK SEMICOLON
			{ break1(); }
		| RETURN opt_expression SEMICOLON
			{ compile((T)$2,LOAD); emit(FUNCRET,currfunc,0); }
		| error SEMICOLON
		;

if_tail
		: ELSE statement
		| /* empty */
		;

/* expressions */

expression
		: primary
		| unary_expr
		| binary_expr
		;

opt_expression
		: expression
		| /* empty */
			{ $$=(int)maketree(T_LIT,0,NIL); }
		;

primary
		: IDENT
			{ $$=(int)maketree(T_ID,(T)lookup(id),NIL); }
		| LITERAL
			{ $$=(int)maketree(T_LIT,value,NIL); }
		| LPAR expression RPAR
			{ $$=$2; }
		| func_name LPAR actual_params RPAR
			{ $$=(int)maketree(CALL,(T)$1,(T)$3); }
		| primary LBRACK expression RBRACK
			{ $$=(int)maketree(DEREF,
			                   maketree(ADD,(T)$1,(T)$3),
			                   NIL); }
		;

func_name
		: IDENT
			{ $$=reffunc(id); }
		;

actual_params
		: expr_list
		| /* empty */
			{ $$=NIL; }
		;

expr_list
		: expr_list COMMA expression
			{ $$=(int)maketree(ARGLINK,(T)$3,(T)$1); }
		| expression
			{ $$=(int)maketree(ARGLINK,(T)$1,NIL); }
		;
			/* actual arguments are linked in reverse order */

unary_expr
		: STAR expression
			{ $$=(int)maketree(DEREF,(T)$2,NIL); }
		| AND primary
			{ $$=(int)maketree(ADRS,(T)$2,NIL); }
		| MINUS expression
			{ $$=(int)maketree(INVSIGN,(T)$2,NIL); }
		| EXCLAM expression
			{ $$=(int)maketree(NOT,(T)$2,NIL); }
		| TILDE expression
			{ $$=(int)maketree(ONECMPL,(T)$2,NIL); }
		| PLUSPLUS primary
			{ $$=(int)maketree(PREINCR,(T)$2,NIL); }
		| MINUSMINUS primary
			{ $$=(int)maketree(PREDECR,(T)$2,NIL); }
		| primary PLUSPLUS
			{ $$=(int)maketree(PSTINCR,(T)$1,NIL); }
		| primary MINUSMINUS
			{ $$=(int)maketree(PSTDECR,(T)$1,NIL); }
		;


binary_expr
		: expression STAR expression
			{ $$=(int)maketree(MULT,(T)$1,(T)$3); }
		| expression SLASH expression
			{ $$=(int)maketree(DIV,(T)$1,(T)$3); }
		| expression PERCENT expression
			{ $$=(int)maketree(MOD,(T)$1,(T)$3); }
		| expression PLUS expression
			{ $$=(int)maketree(ADD,(T)$1,(T)$3); }
		| expression MINUS expression
			{ $$=(int)maketree(SUB,(T)$1,(T)$3); }
		| expression LSHIFT expression
			{ $$=(int)maketree(LSFTOP,(T)$1,(T)$3); }
		| expression RSHIFT expression
			{ $$=(int)maketree(RSFTOP,(T)$1,(T)$3); }
		| expression LT expression
			{ $$=(int)maketree(LTOP,(T)$1,(T)$3); }
		| expression GT expression
			{ $$=(int)maketree(LTOP,(T)$3,(T)$1); }
		| expression LE expression
			{ $$=(int)maketree(LEOP,(T)$1,(T)$3); }
		| expression GE expression
			{ $$=(int)maketree(LEOP,(T)$3,(T)$1); }
		| expression EQEQ expression
			{ $$=(int)maketree(EQOP,(T)$1,(T)$3); }
		| expression NOTEQ expression
			{ $$=(int)maketree(NEOP,(T)$1,(T)$3); }
		| expression AND expression
			{ $$=(int)maketree(ANDOP,(T)$1,(T)$3); }
		| expression UPARROW expression
			{ $$=(int)maketree(XOROP,(T)$1,(T)$3); }
		| expression OR expression
			{ $$=(int)maketree(OROP,(T)$1,(T)$3); }
		| expression ANDAND expression
			{ $$=(int)maketree(LANDOP,(T)$1,(T)$3); }
		| expression OROR expression
			{ $$=(int)maketree(LOROP,(T)$1,(T)$3); }
		| expression EQUAL expression
			{ $$=(int)maketree(ASSIGN,(T)$1,(T)$3); }
		;


/* This grammar contains one shift/reduce conflict: dangling ELSE
   problem.  Yacc's precedence rule solves this problem in favor of
   the usual rule of IF-ELSE matching. */


%%
 
static struct { char *s; int v; }
	keywords[NRES] =  { "auto",     NEGL,
	                    "break",    BREAK,
	                    "case",     NEGL,
	                    "char",     TYPENAME,
	                    "continue", NEGL,
	                    "default",  NEGL,
	                    "do",       NEGL,
	                    "double",   NEGL,
	                    "else",     ELSE,
	                    "extern",   NEGL,
	                    "float",    NEGL,
	                    "for",      NEGL,
	                    "goto",     NEGL,
	                    "if",       IF,
	                    "int",      TYPENAME,
	                    "long",     TYPENAME,
	                    "register", NEGL,
	                    "return",   RETURN,
	                    "short",    TYPENAME,
	                    "sizeof",   NEGL,
	                    "static",   NEGL,
	                    "struct",   NEGL,
	                    "switch",   NEGL,
	                    "typedef",  NEGL,
	                    "union",    NEGL,
	                    "unsigned", NEGL,
	                    "while",    WHILE };

//static int yylex()
int yylex()
{	int l,h,p,x,base;
 
    rescan:
	while (c==' ' || c=='\t' || c=='\n')
		cget();
	tokenline=line;         /* accurately refer to error position */
	if (c==EOF)
		return(EOF);
	if (c>='a' && c<='z' || c>='A' && c<='Z' || c=='_') {
		l=0;
		while (c>='a' && c<='z' || c>='A' && c<='Z' ||
		       c=='_' || c>='0' && c<='9') {
			if (l<IDSIZE)
				id[l++]=c;
			cget();
		}
		id[l]=0;
		l=0;
		h=NRES-1;
		while (l<=h) {
			p=(l+h)/2;
			x=strcompare(id,keywords[p].s);
			if (x==0) {
				if (keywords[p].v==NEGL) {
					yyerror("unsupported keyword");
					goto rescan;
				}
				if (keywords[p].v==TYPENAME) {
					if (strcompare(id,"char")==0)
						basetype=(&chartype);
					else
						basetype=(&inttype);
				}
				return(keywords[p].v);
			}
			if (x<0)
				h=p-1;
			else
				l=p+1;
		}
		return(IDENT);
	}
	else if (c>='0' && c<='9') {
		if (c=='0')
			base=8;
		else
			base=10;
		value=0;
		while (c>='0' && c<='9') {
			if (base==8 && (c=='8' || c=='9'))
				yyerror("8 or 9 in octal number");
			value=value*base+(c-'0');
			cget();
		}
		return(LITERAL);
	}
	else if (c=='\'') {
		cget();
		if (c=='\'') 
			yyerror("null character literal");
		else
			value=charval();
		if (c=='\'')
			cget();
		else
			yyerror("character literal invalid format");
		return(LITERAL);
	}
	else if (c=='\"') {
		value=(int)(&string[strtop]);
		cget();
		while (c!='\"' && c!='\n') 
			enterstr(charval());
		if (c=='\"')
			cget();
		else
			yyerror("string literal invalid format");
		enterstr(0);
		return(LITERAL);
	}
	switch (c) {
	case ',':
		cget();
		return(COMMA);
	case ';':
		cget();
		return(SEMICOLON);
	case '{':
		cget();
		return(LBRACE);
	case '}':
		cget();
		return(RBRACE);
	case '(':
		cget();
		return(LPAR);
	case ')':
		cget();
		return(RPAR);
	case '[':
		cget();
		return(LBRACK);
	case ']':
		cget();
		return(RBRACK);
	case '*':
		cget();
		return(STAR);
	case '&':
		cget();
		if (c=='&') {
			cget();
			return(ANDAND);
		}
		return(AND);
	case '|':
		cget();
		if (c=='|') {
			cget();
			return(OROR);
		}
		return(OR);
	case '+':
		cget();
		if (c=='+') {
			cget();
			return(PLUSPLUS);
		}
		return(PLUS);
	case '-':
		cget();
		if (c=='-') {
			cget();
			return(MINUSMINUS);
		}
		return(MINUS);
	case '/':
		cget();
		if (c=='*') {
			cget();
			do {
				while (c!='*' && c!=EOF)
					cget();
				cget();
			} while (c!='/' && c!=EOF);
			if (c==EOF) {
				yyerror("comment not terminated");
				return(EOF);
			}
			cget();
			goto rescan;
		}
		return(SLASH);
	case '!':
		cget();
		if (c=='=') {
			cget();
			return(NOTEQ);
		}
		return(EXCLAM);
	case '~':
		cget();
		return(TILDE);
	case '%':
		cget();
		return(PERCENT);
	case '<':
		cget();
		if (c=='<') {
			cget();
			return(LSHIFT);
		}
		else if (c=='=') {
			cget();
			return(LE);
		}
		return(LT);
	case '>':
		cget();
		if (c=='>') {
			cget();
			return(RSHIFT);
		}
		else if (c=='=') {
			cget();
			return(GE);
		}
		return(GT);
	case '=':
		cget();
		if (c=='=') {
			cget();
			return(EQEQ);
		}
		return(EQUAL);
	case '^':
		cget();
		return(UPARROW);
	default:
		yyerror("invalid character");
		cget();
		goto rescan;
	}
}

enterstr(v)
int v;
{
	if (strtop>=STRSIZE)
		fatal("string table overflow");
	string[strtop++]=v;
}

int charval()
{	int v,l;

	if (c<040 || c>=0177) {
		yyerror("control character in string");
		cget();
		return(0);
	}
	if (c!='\\') {
		v=c;
		cget();
		return(v);
	}
	cget();
	if (c>='0' && c<='7') {
		v=0;
		l=0;
		while (l<3 && c>='0' && c<='7') {
			v=(v<<3)+(c-'0');
			l++;
			cget();
		}
		return(v);
	}
	switch (c) {
	case 'n':
		v='\n';
		break;
	case 't':
		v='\t';
		break;
	case 'b':
		v='\b';
		break;
	case 'r':
		v='\r';
		break;
	case 'f':
		v='\f';
		break;
	default:
		v=c;
	}
	cget();
	return(v);
}

int cget()
{
	c=getc(source);
	if (c=='\n')
		line++;
}

int copystr(a,b)
char *a,*b;
{
	while (*a++=(*b++))
		;
}

yyerror(s)
char *s;
{
	printf("%4d: %s\n",tokenline,s);
	errcnt++;
}

fatal(s)
char *s;
{
	yyerror(s);
	exit(1);
}
