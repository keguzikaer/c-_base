#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_COLS 20
#define MAX_INPUT 1000

void print_line_with_num();

int main() {
    print_line_with_num();
    return 0;
}

void print_line_with_num() {
    int ch;
    int line = 0;
    int at_begin = 1;

    while ((ch = getchar()) != EOF) {
        if (at_begin) {
            at_begin = 0;
            printf("%d ", ++line);
        }

        putchar(ch);

        if ('\n' == ch) 
            at_begin = 1;
    }

    return;
}
