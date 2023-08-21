#include <stdio.h>

#define a(x) { \
            }  \

#define TRUE (1)

int f_return1() {
    return 1;
}

//int main() 
//{
//    int (*f)() = f_return1;
//    int (*point_arr[])() = {f,};
//
//    printf("%d\n", f());
//    printf("%d\n", point_arr[2]());
//
//    return 0;
//}


int option_a, option_b;

int main(int argc, char **argv) 
{
    //printf("%d\n", argc);
    //printf("%s\n", *(argv++));
    char **temp_ptr = argv;
    while (*temp_ptr != NULL)
        printf("%s ", *temp_ptr++);
    printf("\n");

    temp_ptr = argv;
    while (*++temp_ptr && **temp_ptr == '-')
    {
        char index = *++*temp_ptr;
        if (index == 'a')
            option_a = TRUE;
        else if (index == 'b')
            option_b = TRUE;
    }

    printf("option_a = %d\n", option_a);
    printf("option_b = %d\n", option_b);

    char *str_abcde = "abcde";
    printf("*str_abcde = %c\n", *str_abcde);
    printf("*++str_abcde = %c\n", *++str_abcde);
    printf("*++str_abcde = %c\n", *++str_abcde);
    printf("*(str_abcde + 2) = %c\n", *(str_abcde + 2));

    return 0;
}