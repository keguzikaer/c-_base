#include <stdio.h>
#include <stdlib.h>

int main() 
{
    perror("test err.");
    perror("test err2.");

    //exit(EXIT_SUCCESS);
    printf("====1====\n");
    fflush(stdout);
    printf("====2====\n");

    int x = FOPEN_MAX;
    printf("FOPEN_MAX: %d\n", x);
    printf("FILENAME_MAX: %d\n", FILENAME_MAX);

    //char a = getchar();
    //putchar(a);

    //char str[20];
    //gets(str);
    //printf("str: %s\n", str);

    FILE* file_ptr = fopen("./test.txt", "a+");
    if (!file_ptr)
    {
        perror("file_ptr is null.");
        exit(EXIT_FAILURE);
    }

    char c;
    while ((c = fgetc(file_ptr)) != EOF)
    {
        printf("%c", c);
    }
    printf("\n");

    int result = fputc('q', file_ptr);
    printf("result: %d\n", result);
    
    result = fclose(file_ptr);
    printf("result: %d\n", result);


    return 0;
}