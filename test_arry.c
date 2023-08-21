#include <stdio.h>
#include <string.h>
#include <stddef.h>

void print_array(int *array, int len);

typedef struct {
    int age;
    char a;
    char b;
} people;

typedef struct {
    char b;
    int age;
    char a;
} people2;

int main() {
    int arr[5] = {8, 2, 3, 4, 5};
    int len = sizeof(arr)/sizeof(int);
    print_array(arr, len);
    arr[0] = 10;
    print_array(arr, len);

    char *test_str = "hello";
    printf("%d\n", strlen(test_str));

    char test_str2[100] = "hello";
    printf("%d\n", strlen(test_str2));

    char *result = strstr(test_str, test_str2);
    if (!result)
        printf("result: null\n");
    else 
        printf("result = %s\n", result);

    printf("sizeof(people) = %d\n", sizeof(people));
    printf("sizeof(people2) = %d\n", sizeof(people2));
    printf("offsetof(people2, age) = %d\n", offsetof(people2, age));
    return 0;
}

void print_array(int *array, int len) {
    for (int index = 0; index < len; ++index) 
        printf("%d ", array[index]);
    printf("\n");
}