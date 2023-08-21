#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main () {
    char str1[] = "abc";
    char str2[] = "123";
    system("ls");
    printf("sizeof(str1): %d\n", sizeof(str1));
    strcat(str1, str2);
    printf("sizeof(str1): %d\n", sizeof(str1));
    printf("%s\n", str1);

    char buf[BUFSIZ];
    int n;
    int index = 0;
    while ((n = read(0, buf, BUFSIZ)) > 0) {
        write(2, buf, n);
        printf("%d\n", index++);
    }

    return 0;
}