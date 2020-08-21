CC=gcc

all:
	$(CC) match_postref.c -o ../bin/postref
	$(CC) greentext.c -o ../bin/greentext

clean:
	rm ../bin/*
