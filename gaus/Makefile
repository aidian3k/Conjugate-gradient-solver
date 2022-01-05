a.out:main.o gauss.o backsubst.o matrix.o
	$(CC) $^
main.o: matrix.c backsubst.c gauss.c
matrix.o: matrix.c matrix.h
gauss.o: gauss.c gauss.h
backsubst.o: backsubst.c backsubst.h
clear:
	rm *.o
