#include <stdio.h>
#include <inttypes.h>

/**
 * Find lines that start with > line and replace them for
 * <span class="green">&gt; line</span>
 * 
 * Version 0.1
 */

#define MARK_CHAR '>'
#define END_LINE '\n'


int main(int argc, char** argv)
{
    if (argc != 2)
        return 1;

    char* c =  argv[1];
    uint8_t start_line = 1;
    uint8_t print_at_end = 0;

    while (*c)
    {
        if (start_line)
        {
            start_line=0;
            if (*c == MARK_CHAR)
            {
                c++;
                print_at_end=1;
                printf("<span class=\"green\">>");
            }
        } else if (*c == END_LINE)
        {
            start_line=1;
            if (print_at_end)
            {
                print_at_end=0;
                printf("</span>");
            }
        }

        putc(*c, stdout);
        c++;
    }

    return 0;
}