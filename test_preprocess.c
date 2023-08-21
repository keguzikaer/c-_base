#include <stdio.h>

// define 结尾不加分号，使用时加分号，防止被替换为两条语句
// 以下这种情况就会发生错误
// if (...)
//     DEBUG_PRINT;
// else 
//     ...
#define DEBUG_PRINT \
    printf("file: %s, line: %d, x = %d\n", __FILE__, __LINE__, x)

#define PRINT(FORMAT, VALUE) \
    printf(#VALUE " value is " FORMAT "\n", VALUE)

#define ADD_TO_SUM(index, value) \
    x##index += value;

//#define VERISON (1)

int main() {
    //  预处理符号
    printf("__FILE__ = %s\n", __FILE__);
    printf("__LINE__ = %d\n", __LINE__);
    printf("__DATE__ = %s\n", __DATE__);
    printf("__TIME__ = %s\n", __TIME__);
    printf("__STDC__ = %d\n", __STDC__);

    // 
    int x = 1;
    DEBUG_PRINT;
    PRINT("%d", x + 1);

    int x2 = 0;
    ADD_TO_SUM(2, 10);
    printf("x2 = %d\n", x2);

    //int array[ARRAY_SIZE];
    //array[9] = 1;
    //printf("array[9] = %d\n", array[9]);
#ifndef VERISON
    #define VERISON 1
#endif

#ifdef VERISON
    #undef VERISON
    #define VERISON 2
#endif

#if VERISON == 1
    printf("VERISON1\n");
#elif VERISON == 2
    printf("VERISON2\n");
#endif

//#if VERISON == 2
//    #error version err
//#endif

    return 0;
}