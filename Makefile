CC=gcc

all:
	$(CC) match_postref.c -o ../bin/postref

clean:
	rm ../bin/*
