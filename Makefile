# make clean all #cleans and rebuilds everything

CFLAGS=-Wall -g

all:
	cc $(CFLAGS) ex1.c -o ex1
	cc $(CFLAGS) ex3.c -o ex3
	cc $(CFLAGS) ex4.c -o ex4
	cc $(CFLAGS) ex5.c -o ex5
clean:
	rm -f ex*.exe ex1 ex2 ex3 ex4 ex5 ex6 ex7 ex8 ex9
	rm -f ex10 ex11 ex12 ex13 ex14 ex15 ex16 ex17 ex18
	rm -f ex21 ex23 ex24 ex25 ex26 ex27
