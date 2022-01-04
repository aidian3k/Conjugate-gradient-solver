solver: main.o gradient.o matrix.o
	$(CC) $^
main.o: gradient.c matrix.c main.c
matrix.o: matrix.c 
gradient.o: matrix.c  gradient.c main.c
clean:
	rm *.o
