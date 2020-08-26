// vim: expandtab
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

/*
 * Find expressions matching /#[0-9]{1,4}/ (#44) and replace them for
 *  - <a href="#44" onclick="highlight('44');">#44</a>
 *  - \Zb\Z5#44\Zn
 *  - \e[31m#44\e[0m
 *
 * Version 0.2
 */

enum {
    Mark = '#'
};

char buf[4 +1];




#ifdef HTML_FORMAT
void print_num() {
    fprintf(stdout,
        "<a href=\"%c%s\" onclick=\"highlight('%s');\">%c%s</a>",
        Mark, buf, buf, Mark, buf);
}

#elif defined SSH_FORMAT
void print_num() {
    fprintf(stdout,
        "\\\\\\\\Z5\\\\\\\\Zb%c%s\\\\\\\\Zn",
        Mark, buf);
}

#else /*terminal*/
void print_num() {
    fprintf(stdout,
        "\033[31m%c%s\033[0m",
        Mark, buf);
}
#endif




int
main(int argc, char *argv[])
{
    if (argc != 2) return 1;
    char *s = argv[1];
    int i;
    //
    for (;;) {
        if (*s == Mark) {
            for (s += 1, i = 0; isdigit(*s); s++, i++) {
                if (i >= sizeof(buf) -1) break;
                buf[i] = *s;
            };
            buf[i] = 0;
            if (i < 1) {
                putc(Mark,stdout);
                continue;
            };
            print_num();
        } else if (*s) {
            putc(*s++, stdout);
        } else {
            break;
        };
    }
    return 0;
}
