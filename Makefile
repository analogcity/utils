CC=gcc
#CC=tcc

all:
	mkdir -p bin
	# greentext
	$(CC) -DHTML_FORMAT greentext.c  -o bin/greentext
	$(CC) -DSSH_FORMAT  greentext.c  -o bin/ssh_greentext
	# postref
	$(CC) -DHTML_FORMAT postref.c    -o bin/postref
	$(CC) -DSSH_FORMAT  postref.c    -o bin/ssh_postref
	# <br> in HTML
	$(CC) -DHTML_FORMAT endline.c    -o bin/endline

install: all
	mv -f bin/* ../bin/

clean:
	rm bin/*

uninstall:
	rm ../bin/*
