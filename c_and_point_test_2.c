#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void check_curly_bracket();
void printf_test();

int main() {
    // 1  gcc c_and_point_test_2.c -trigraphs
    // /? 防止被解释为三字母词，可以防止告警
    printf("Three char \?\?(! \n");

    // 2
    // check_curly_bracket();

    // 3
    printf_test();
    return 0;
}

void check_curly_bracket() {
    int ch;
    int left_bracket_count = 0;
    int right_bracket_count = 0;
    int result = 1;
    while ((ch = getchar()) != EOF) {
        if ('{' == ch) 
            ++left_bracket_count;
        else if ('}' == ch) {
            if (--left_bracket_count < 0) {
                result = 0;
                break;
            }
            else {
                ++right_bracket_count;
            }
        }
        else if ('\n' == ch) 
            break;
    }
    if (result && 0 == left_bracket_count && 0 == right_bracket_count)
        printf("True\n");
    else 
        printf("False\n");
}

void printf_test() {
    printf("Blunder\?\?!??\n");
}
