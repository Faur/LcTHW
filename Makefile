# make clean all #cleans and rebuilds everything

CFLAGS=-Wall -g

all:
	cc $(CFLAGS) ex1.c -o ex1
	cc $(CFLAGS) ex3.c -o ex3
clean:
	rm -f ex*.exe