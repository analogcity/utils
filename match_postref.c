#include <stdio.h>
#include <inttypes.h>

/**
 * Find expressions like #44 and replace them for
 * <a href="#44" onclick="highlight('44');">#44</a>
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
                "<a href=\\\"%c%s\\\" onclick=\\\"highlight(\\'%s\\');\\\">%c%s</a>",
                MARK_CHAR, num, num, MARK_CHAR, num
                );
            for (size_t i = 0; i < MAX_NUMBERS; num[i++]='\0');
            continue;


        }
        putc(*c,stdout);
        c++;
    }

    return 0;
}
