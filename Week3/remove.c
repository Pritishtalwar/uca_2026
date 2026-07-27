#include <stdio.h>

int main() {
    int c, d;
    int in_string = 0, in_char = 0;

    while ((c = getchar()) != EOF) {
        if (!in_string && !in_char && c == '/') {
            d = getchar();

            if (d == '/') {
                while ((c = getchar()) != EOF && c != '\n');
                if (c == '\n')
                    putchar('\n');
            } else if (d == '*') {
                int prev = 0;
                while ((c = getchar()) != EOF) {
                    if (prev == '*' && c == '/')
                        break;
                    prev = c;
                }
            } else {
                putchar(c);
                if (d != EOF)
                    ungetc(d, stdin);
            }
        } else {
            putchar(c);

            if (c == '"' && !in_char)
                in_string = !in_string;
            else if (c == '\'' && !in_string)
                in_char = !in_char;
            else if (c == '\\' && (in_string || in_char)) {
                c = getchar();
                if (c != EOF)
                    putchar(c);
            }
        }
    }

    return 0;
}
