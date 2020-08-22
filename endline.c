#include <stdio.h>
#include <inttypes.h>

/**
 * Replaces the endline character for the
 * <br> html tag
 * 
 * Version 0.1
 */

#define MARK_CHAR '\n'
#define END_LINE "<br>"

int main(int argc, char** argv)
{
    if (argc != 2)
        return 1;

    char* c =  argv[1];

    while (*c)
    {
        if (*c == MARK_CHAR)
        {
            printf(END_LINE);
            c++;
        }
        
        if (*c)
        {
            putc(*c, stdout);
            c++;
        }
    }

    return 0;
}