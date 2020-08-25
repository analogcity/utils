#include <stdio.h>
#include <inttypes.h>

/**
 * Replaces the endline character for the
 * <br> html tag
 * 
 * Version 0.1
 */

enum {
    Mark = '\n',
};

const char *str = "<br>";


int main(int argc, char *argv[])
{
    if (argc != 2) return 1;
    char *s =  argv[1];
    //
    for (;;s++) {
        if (*s == Mark) {
            fputs(str, stdout);
        } else  if (*s) {
            putc(*s, stdout);
        } else {
            break;
        };
    }
    return 0;
}