CC=gcc

all:
	$(CC) match_postref.c -o ../bin/postref
	$(CC) greentext.c -o ../bin/greentext
	$(CC) endline.c -o ../bin/endline

clean:
	rm ../bin/*
