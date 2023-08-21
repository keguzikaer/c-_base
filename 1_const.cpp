#include <iostream>
#include <string.h>

int main()
{
    int a = 1;
    int b = 2;

    int *ptr2 = &b;
    int * const ptr = &a;

    *ptr = 2;
    const int *ptr3 = &a;
    ptr3 = ptr2;

    return 0;
}
