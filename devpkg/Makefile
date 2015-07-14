PREFIX?=/usr/local
	# ?= : Set PREFIX equal to this, unless PREFIX is already set
CFLAGS=-g -Wall -I${PREFIX}/apr/include/apr-1 -I${PREFIX}/apr/include/apr-util-1
LDFLAGS=-L${PREFIX}/apr/lib -lapr-1 -pthread -laprutil-1

all: devpkg

devpkg: bstrlib.o db.o shell.o commands.o

install: all
	install -d $(DESTDIR)/$(PREFIX)/bin/
	install devpgk $(DESTDIR)/$(PREFIX)/bin/

clean:
	rm -f *.o devpkg *.dSYM




