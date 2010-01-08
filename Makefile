all: c--

c--: main.o y.tab.o code.o idtab.o tree.o intp.o
		gcc -Wall *.o -o c--

main.o: main.c
	gcc -Wall -c main.c

y.tab.o: common.h parse1.tab.c
	gcc -Wall -c y.tab.c

parse1.tab.c: parse1.y
	bison parse1.y

code.o: common.h code.c
	gcc -Wall -c code.c

idtab.o: common.h idtab.c
	gcc -Wall -c idtab.c

tree.o: common.h tree.c
	gcc -Wall -c tree.c

intp.o: common.h intp.c
	gcc -Wall -c -O intp.c

clean:
	rm -f parse1.tab.c
	rm -f *.o *~ c--
