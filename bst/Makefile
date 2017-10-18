all: bstDemo

CFLAGS=-g -O3

# Symbols helpful for understanding the productions
#   $@ is the production's target
#   $^ are the production's prerequisites

bstDemo: bstree.o bstDemo.o
	cc $^ -o $@

personel: personel.o bstree.o
	cc $^ -o $@	

personel.o: personel.c personel.h bstree.o
	cc -c $(CFLAGS) personel.c personel.h bstree.o

bstree.o: bstree.c bstree.h
	cc -c $(CFLAGS) bstree.c bstree.h

bstDemo.o: bstDemo.c bstree.h
	cc -c $(CFLAGS) bstDemo.c

clean:
	rm -f *.o bstDemo personel

demo: bstDemo
	./bstDemo

run: personel
	./personel
