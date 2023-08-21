#include <stdio.h>
#include <time.h>

int main()
{
    time_t a = -1;
    printf("%lu\n", a);
    char *time_str = ctime(&a);
    printf("%s\n", time_str);

    time_t b = a - 1;
    printf("%lu\n", b);
    time_str = ctime(&b);
    printf("%s\n", time_str);
}