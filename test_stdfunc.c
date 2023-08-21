#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <signal.h>
#include <assert.h>
#include <stdlib.h>

void SIGTERM_handler(int a) 
{
    printf("SIGTERM_handler: %d\n", a);
}

void SIGTERM_handler2(int a) 
{
    printf("SIGTERM_handler2: %d\n", a);
}

int compare(void const *a, void const *b) 
{
    return *(int *)a > *(int *)b;
}

int compare2(void const *a, void const *b) 
{   
    if (*(int *)a == *(int *)b)
        return 0;
    else if (*(int *)a > *(int *)b)
        return 1;
    else 
        return -1;
}

int print_arr(int *arr, int count) 
{
    for (int i = 0; i < count; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() 
{
    clock_t start = clock();
    printf("start = %ld\n", start);
    srand(time(0));
    int value = rand();
    printf("%d\n", value);

    long num = strtol("31123232323123123", NULL, 10);
    printf("%llu\n", num);

    for (int i = 0; i < 99999999; ++i);

    clock_t end = clock();
    double used = (double)(end - start) / CLOCKS_PER_SEC;
    printf("end = %ld, used = %f\n", end, used);

    void (* before_handler)(int) = signal(SIGTERM, &SIGTERM_handler);
    before_handler = signal(SIGTERM, &SIGTERM_handler2);
    if (before_handler)
    {
        printf("use before handler\n");
        before_handler(SIGTERM);
    }
    raise(SIGTERM);

    assert(0);

    time_t cur_time = time(NULL);
    printf("cur_time = %d\n", cur_time);
    char *cur_time_str = ctime(&cur_time);
    printf("cur_time_str = %s", cur_time_str);
    ctime(&cur_time);
    printf("cur_time_str = %s", cur_time_str);

    struct tm *tm_s = localtime(&cur_time);

    
    //system("grep include ./*");
    char *env_home = getenv("TEST");
    printf("env_home = %s\n", env_home);

    int arr[10] = {5, 2, 6, 4, 1, 3};
    qsort(arr, 6, sizeof(int), compare);
    print_arr(arr, 6);

    int index = 2;
    int *p = bsearch(&index, arr, 6, sizeof(int), compare2);
    if (p != NULL)
        printf("p = %d\n", *p);

    return 0;
}