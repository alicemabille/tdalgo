all: pile main

main : pile main.c
	gcc -o TD8 main.c pile.o -g

pile : DPile.c
	gcc -c DPile.c -o pile.o -g

clean :
	rm ./*.o TD8
