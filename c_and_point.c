#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_COLS 20
#define MAX_INPUT 1000

int read_column_numbers(int columns[], int max);
void rearrange(char *output, const char *input,
               int n_columns, const int columns[]);

int main() {
    int n_columns;
    int columns[MAX_COLS];
    char input[MAX_INPUT];
    char output[MAX_INPUT];

    n_columns = read_column_numbers(columns, MAX_COLS);

    while (gets(input) != NULL) {
        printf("input: %s\n", input);
        rearrange(output, input, n_columns, columns);
        printf("output: %s\n", output);
    }
    return 0;
}

int read_column_numbers(int columns[], int max) {
    int num = 0;
    int ch;
    
    while (num < max && scanf("%d", &columns[num]) == 1 
        && columns[num] >= 0)
        num += 1;
    
    return num;
}

void rearrange(char *output, const char *input,
               int n_columns, const int columns[]) {
    int col;
    int output_col = 0;
    int len = strlen(input);

    for (col = 0; col < n_columns; col += 2) {
        int nchars = columns[col + 1] - columns[col] + 1;

        if (columns[col] >= len
            || output_col == MAX_INPUT - 1)
            break;
        
        if (output_col + nchars > MAX_INPUT - 1)
            nchars = MAX_INPUT - output_col - 1;

        strncpy(output + output_col, input + columns[col], nchars);
        output_col += nchars;
    }
    output[output_col] = '\n';
}