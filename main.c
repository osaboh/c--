/****************************************************************

Compiler-Interpreter of C--, a small subset of C

****************************************************************

features not included in this subset:
. type definitions
. struct/union types
. extern/static definitions
. type specifications of functions and their parameters
. initial values
. internal blocks
. unsigned, float, double types
. switch, do, for, continue statements
. goto statements, labels
. conditional expressions, comma operators
. casts (type conversion), sizeof operators
. assignment operators
very small, yet usable subset
*/


#include <stdio.h>
#include <stdlib.h>

FILE *source;
int errcnt = 0;

int main(int argc, char *argv[])

{	int debug,trace,selparse,nogo;
	int filecnt;
	int i,j;
	char *s,*filename;

	debug=0;
	trace=0;
	selparse=0;
	nogo=0;
	filecnt=0;
	for (i=1; i<argc; i++) {
		s=argv[i];
		if (s[0]=='-')
			for (j=1; s[j]; j++)
				switch (s[j]) {
				case 'd': debug=1;
					break;
				case 't': trace=1;
					break;
				case 's': selparse=1;
					break;
				case 'n': nogo=1;
					break;
				default:  printf("option (%c) ",s[j]);
					printf("not recognized\n");
					break;
				}
		else {
			filecnt++;
			if (filecnt<=1)
				filename=s;
		}
	}
	if (filecnt==0)
		source=stdin;
	else {
		if (filecnt>1)
			printf("multiple source file is not supported\n");
		source=fopen(filename,"r");
		if (source==NULL) {
			printf("%s: open failed\n",filename);
			exit(1);
		}
	}
	if (selparse) {
		fprintf(stderr, "Implement parse()\n");
		//parse();
	} else
		yyparse();
	if (source!=stdin)
		fclose(source);
	if (debug)
		printcode();
	if (errcnt==0 && !nogo)
		interpret(trace);

	return 0;
}
