# make clean all #cleans and rebuilds everything

CFLAGS=-Wall -g

all:
	cc $(CFLAGS) ex1.c -o ex1
	cc $(CFLAGS) ex3.c -o ex3
	cc $(CFLAGS) ex4.c -o ex4
	cc $(CLFAGS) ex5.c -o ex5
clean:
	rm -f ex*.exe
