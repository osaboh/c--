/* Common data definitions */

#define NIL     0

/* type definitions */

typedef struct TYPE_x
	{ int kind,size; struct TYPE_x *next; } TYPE;

	/* kind:  '*' - pointer type
	          '[' - array type
	          '-' - numeric type (int, char) */


typedef struct { TYPE *t; int base,offset; } IDPROP;

typedef struct TREE_x 
	{ int val; struct TREE_x *left,*right; } TREE;


/* tree headers */

#define T_ID    1001
#define T_LIT   1002

#define DEREF   1003
#define ADRS    1004
#define INVSIGN 1005
#define NOT     1006
#define ONECMPL 1007
#define PREINCR 1008
#define PREDECR 1009
#define PSTINCR 1010
#define PSTDECR 1011

#define MULT    1012
#define DIV     1013
#define MOD     1014
#define ADD     1015
#define SUB     1016
#define LSFTOP  1017
#define RSFTOP  1018
#define LTOP    1019
#define LEOP    1021
#define EQOP    1023
#define NEOP    1024
#define ANDOP   1025
#define XOROP   1026
#define OROP    1027
#define LANDOP  1028
#define LOROP   1029
#define ASSIGN  1030

#define CALL    1031
#define ARGLINK 1032

/* operation codes */

#define LOAD      1101
#define LOADADRS  1102
#define LOADCONST 1103
#define EXCHANGE  1104
#define POPUP     1105
#define FUNCENT   1106
#define FUNCRET   1107
#define JUMP      1108
#define FJUMP     1109
#define TJUMP     1110
#define COPYVAL   1111
#define STOP      1112

/* code buffer */

#define CODEMAX 5000
typedef struct { int op,f1,f2; } codetype;
