/* Recursive descent parser  (no error recovery)

    . This parser and the Yacc generated parser give the same
      result except error messages.
    . This module should be concatenated with y.tab.c to be compiled. */


#define insymbol()  sy=yylex()

static int sy;
static TREE *expression(),*exp1(),*exp2(),*exp3(),*exp4(),
            *exp5(),*exp6(),*exp7(),*exp8(),*exp9(),*exp10(),
            *unary(),*primary();
extern TREE *maketree();
extern IDPROP *lookup();

parse()
{
	insymbol();
	initcode();
	while (sy!=EOF)
		external_def();
	checkfunc();
}

static external_def()
{
	if (sy==IDENT)
		function_decl();
	else if (sy==TYPENAME)
		var_decl();
	else
		error("unrecognized external definition");
}

static function_decl()
{
	enterfunc(id);
	insymbol();
	testdelim(LPAR,"left parenthesis");
	if (sy==RPAR) 
		insymbol();
	else {
		for (;;) {
			if (sy!=IDENT)
				error("formal parameter is not identifier");
			enter(id,&inttype);
			insymbol();
			if (sy!=COMMA)
				break;
			insymbol();
		}
		testdelim(RPAR,"right parenthesis");
	}
	endparam();
	testdelim(LBRACE,"left brace");
	local_decl_list();
	statement_list();
	testdelim(RBRACE,"right brace");
	endfunc();
}

static local_decl_list()
{
	while (sy==TYPENAME) 
		var_decl();
}

static var_decl()
{	extern TYPE *reverse();

	do {
		insymbol();
		ctype=NIL;
		cleartree();
		declarator();
		enter(declid,reverse(ctype,basetype));
	} while (sy==COMMA);
	testdelim(SEMICOLON,"semicolon");
}

static declarator()
{	TREE *p;

	if (sy==IDENT) { 
		copystr(declid,id);
		insymbol();
	}
	else if (sy==LPAR) {
		insymbol();
		declarator();
		testdelim(RPAR,"right parenthesis");
	}
	else if (sy==STAR) {
		insymbol();
		declarator();
		ctype=newtype('*',0,ctype);
	}
	else 
		error("invalid declarator");
	while (sy==LBRACK) {
		insymbol();
		if (sy==RBRACK) {
			p=maketree(T_LIT,0,NIL);
			insymbol();
		}
		else { 
			p=expression();
			testdelim(RBRACK,"right bracket");
		}
		ctype=newtype('[',eval(p),ctype);
	}
}

static statement_list()
{
	while (sy!=RBRACE && sy!=EOF) 
		statement();
}

static statement()
{	TREE *p;

	if (sy==SEMICOLON)
		insymbol();
	else if (sy==LBRACE) {
		insymbol();
		statement_list();
		testdelim(RBRACE,"right brace");
	}
	else if (sy==IF) {
		insymbol();
		testdelim(LPAR,"left parenthesis");
		cleartree();
		p=expression();
		testdelim(RPAR,"right parenthesis");
		if1(compile(p,FJUMP));
		statement();
		if2();
		if (sy==ELSE) {
			insymbol();
			statement();
		}
		if3();
	}
	else if (sy==WHILE) {
		insymbol();
		while1();
		testdelim(LPAR,"left parenthesis");
		cleartree();
		p=expression();
		testdelim(RPAR,"right parenthesis");
		while2(compile(p,FJUMP));
		statement();
		while3();
	}
	else if (sy==BREAK) {
		break1();
		insymbol();
		testdelim(SEMICOLON,"semicolon");
	}
	else if (sy==RETURN) {
		insymbol();
		if (sy==SEMICOLON) {
			p=maketree(T_LIT,0,NIL);
			insymbol();
		}
		else {
			p=expression();
			testdelim(SEMICOLON,"semicolon");
		}
		compile(p,LOAD);
		emit(FUNCRET,currfunc,0);
	}
	else {
		cleartree();
		p=expression();
		testdelim(SEMICOLON,"semicolon");
		compile(p,POPUP);
	}
}

static TREE *expression()
{	TREE *p;

	p=exp1();
	if (sy==EQUAL) {
		insymbol();
		p=maketree(ASSIGN,p,expression());
	}
	return(p);
}

static TREE *exp1()
{	TREE *p;

	p=exp2();
	while (sy==OROR) {
		insymbol();
		p=maketree(LOROP,p,exp2());
	}
	return(p);
}

static TREE *exp2()
{	TREE *p;

	p=exp3();
	while (sy==ANDAND) {
		insymbol();
		p=maketree(LANDOP,p,exp3());
	}
	return(p);
}

static TREE *exp3()
{	TREE *p;

	p=exp4();
	while (sy==OR) {
		insymbol();
		p=maketree(OROP,p,exp4());
	}
	return(p);
}

static TREE *exp4()
{	TREE *p;

	p=exp5();
	while (sy==UPARROW) {
		insymbol();
		p=maketree(XOROP,p,exp5());
	}
	return(p);
}

static TREE *exp5()
{	TREE *p;

	p=exp6();
	while (sy==AND) {
		insymbol();
		p=maketree(ANDOP,p,exp6());
	}
	return(p);
}

static TREE *exp6()
{	TREE *p;
	int op;

	p=exp7();
	if (sy==EQEQ || sy==NOTEQ) {
		if (sy==EQEQ)
			op=EQOP;
		else
			op=NEOP;
		insymbol();
		p=maketree(op,p,exp7());
	}
	return(p);
}

static TREE *exp7()
{	TREE *p;
	int op;

	p=exp8();
	if (sy==LE || sy==LT) {
		if (sy==LE)
			op=LEOP;
		else
			op=LTOP;
		insymbol();
		p=maketree(op,p,exp8());
	}
	else if (sy==GE || sy==GT) {
		if (sy==GE)
			op=LEOP;
		else
			op=LTOP;
		insymbol();
		p=maketree(op,exp8(),p);
	}
	return(p);
}

static TREE *exp8()
{	TREE *p;
	int op;

	p=exp9();
	while (sy==LSHIFT || sy==RSHIFT) {
		if (sy==LSHIFT)
			op=LSFTOP;
		else
			op=RSFTOP;
		insymbol();
		p=maketree(op,p,exp9());
	}
	return(p);
}

static TREE *exp9()
{	TREE *p;
	int op;

	p=exp10();
	while (sy==PLUS || sy==MINUS) {
		if (sy==PLUS) 
			op=ADD;
		else
			op=SUB;
		insymbol();
		p=maketree(op,p,exp10());
	}
	return(p);
}

static TREE *exp10()
{	TREE *p;
	int op;

	p=unary();
	while (sy==STAR || sy==SLASH || sy==PERCENT) {
		if (sy==STAR)
			op=MULT;
		else if (sy==SLASH)
			op=DIV;
		else
			op=MOD;
		insymbol();
		p=maketree(op,p,unary());
	}
	return(p);
}

static TREE *unary()
{	TREE *p;
	int op;

	if (sy==STAR) {
		insymbol();
		p=maketree(DEREF,unary(),NIL);
	}
	else if (sy==AND) {
		insymbol();
		p=maketree(ADRS,primary(),NIL);
	}
	else if (sy==MINUS) {
		insymbol();
		p=maketree(INVSIGN,unary(),NIL);
	}
	else if (sy==EXCLAM) {
		insymbol();
		p=maketree(NOT,unary(),NIL);
	}
	else if (sy==TILDE) {
		insymbol();
		p=maketree(ONECMPL,unary(),NIL);
	}
	else if (sy==PLUSPLUS) {
		insymbol();
		p=maketree(PREINCR,primary(),NIL);
	}
	else if (sy==MINUSMINUS) {
		insymbol();
		p=maketree(PREDECR,primary(),NIL);
	}
	else {
		p=primary();
		if (sy==PLUSPLUS || sy==MINUSMINUS) {
			if (sy==PLUSPLUS)
				op=PSTINCR;
			else
				op=PSTDECR;
			insymbol();
			p=maketree(op,p,NIL);
		}
	}
	return(p);
}

static TREE *primary()
{	TREE *p;
	int f;

	if (sy==IDENT) {
		insymbol();
		if (sy!=LPAR) 
			p=maketree(T_ID,lookup(id),NIL);
		else {
			f=reffunc(id);
			insymbol();
			p=NIL;
			if (sy==RPAR) 
				insymbol();
			else {
				for (;;) {
					p=maketree(ARGLINK,expression(),p);
					if (sy!=COMMA)
						break;
					insymbol();
				}
				testdelim(RPAR,"right parenthesis");
			}
			p=maketree(CALL,f,p);
		}
	}
	else if (sy==LITERAL) {
		p=maketree(T_LIT,value,NIL);
		insymbol();
	}
	else if (sy==LPAR) {
		insymbol();
		p=expression();
		testdelim(RPAR,"right parenthesis");
	}
	else
		error("unrecognized primary");
	while (sy==LBRACK) {
		insymbol();
		p=maketree(DEREF,maketree(ADD,p,expression()),NIL);
		testdelim(RBRACK,"right bracket");
	}
	return(p);
}

static testdelim(symbol,message)
int symbol;
char *message;
{	char *s,*t;
	char buff[256];

	if (sy!=symbol) {
		s=buff;
		while (*message)
			*s++=(*message++);
		t=" expected";
		while (*t)
			*s++=(*t++);
		*s=0;
		error(buff);
	}
	insymbol();
}

static error(s)                   /* report error, no recovery */
char *s;
{
	yyerror(s);
	exit(1);
}
