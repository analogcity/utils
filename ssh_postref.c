#include <stdio.h>
#include <inttypes.h>

/**
 * Find expressions like #44 and replace them for
 * \Zb\Z5#44\Zn
 * 
 * Version 0.1
 */

#define MAX_NUMBERS 4
#define MARK_CHAR   '#'

int main(int argc, char** argv)
{
    if (argc != 2)
        return 1;

    char num[ MAX_NUMBERS+1 ];
    uint8_t iter = 0;

    char* c = argv[1];

    for (size_t i = 0; i < MAX_NUMBERS; num[i++]='\0');

    while (*c)
    {
        if (*c == MARK_CHAR)
        {
            c++;
            while (*c > 47 && *c < 58 && iter < MAX_NUMBERS)
            {
                num[iter] = *c;
                iter++;
                c++;
            }
            
            if (iter < 1) {
                putc(MARK_CHAR,stdout);
                continue;
            }

            iter=0;
            fprintf(
                stdout,
                "\\\\\\\\Z5\\\\\\\\Zb%c%s\\\\\\\\Zn",
                MARK_CHAR, num
                );
            for (size_t i = 0; i < MAX_NUMBERS; num[i++]='\0');
            continue;


        }

        if (*c)
        {
            putc(*c,stdout);
            c++;
        }
    }

    return 0;
}
