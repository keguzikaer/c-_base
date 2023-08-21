#include <stdio.h>
#include <stdlib.h>

#define STACK_TYPE int
#define MAX_STACK_SIZE (2048)
#define TRUE (1)
#define FALSE (0)

typedef struct STACK {
    int index;
    STACK_TYPE *data;
} stack;

void initStack(stack *st) {
    st->index = -1;
    st->data = (STACK_TYPE *)malloc(MAX_STACK_SIZE * sizeof(STACK_TYPE));
}

void destroyStack(stack *st) {
    if (st) {
        if (st->data)
            free(st->data);
        free(st);
        st = NULL;
    }
}

int top(stack *st, STACK_TYPE *value) {
    if (st->index >= 0) {
        *value = st->data[st->index];
        return TRUE;
    }
    else 
        return FALSE;
}

int push(stack *st, STACK_TYPE value) {
    if (st->index < MAX_STACK_SIZE - 1) {
        st->index += 1;
        st->data[st->index] = value;
        return TRUE;
    }
    else 
        return FALSE;
}

int pop(stack *st) {
    if (st->index >= 0) {
        st->index -= 1;
        return TRUE;
    }
    else 
        return FALSE;
}

int main() 
{
    stack a;
    initStack(&a);
    printf("%d\n", a.index);
    push(&a, 1);
    push(&a, 2);
    push(&a, 3);
    push(&a, 4);

    int value = 0;
    if (top(&a, &value))
        printf("%d\n", value);
    pop(&a);
    if (top(&a, &value))
        printf("%d\n", value);
    pop(&a);
    if (top(&a, &value))
        printf("%d\n", value);
    pop(&a);
    if (top(&a, &value))
        printf("%d\n", value);



    // 错误例子 想把指针传入函数中动态申请空间是错误的,函数是值传递,直接对指针赋值在函数结束后指针消失,实际并没有对传递的指针进行初始化
    /*
    printf("-------------\n");
    stack *b;
    printf("%d\n", b);
    initStack(b);
    printf("%d\n", b);
    push(b,1);
    int value = 0;
    if (top(b, &value))
        printf("%d\n", value);
    */


    return 0;
}
