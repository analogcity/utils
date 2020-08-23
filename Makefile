CC=gcc

all:
	$(CC) match_postref.c -o ../bin/postref
	$(CC) greentext.c -o ../bin/greentext
	$(CC) endline.c -o ../bin/endline
	$(CC) ssh_greentext.c -o ../bin/ssh_greentext
	$(CC) ssh_postref.c -o ../bin/ssh_postref

clean:
	rm ../bin/*
