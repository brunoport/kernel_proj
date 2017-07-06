/*
 * Uso da nova chamada de sistema
 */
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int n1 = 50;
    int n2 = 5;

    char o = '+';
    int r = syscall(384,n1,n2,o);
    printf("-------\nex-mycall: (%d, %d, %c) \nRetorno da chamada de sistema: %d.\n", n1, n2, o, r);

    o = '-';
    r = syscall(384,n1,n2,o);
    printf("-------\nex-mycall: (%d, %d, %c) \nRetorno da chamada de sistema: %d.\n", n1, n2, o, r);

    o = '*';
    r = syscall(384,n1,n2,o);
    printf("-------\nex-mycall: (%d, %d, %c) \nRetorno da chamada de sistema: %d.\n", n1, n2, o, r);

    o = '/';
    r = syscall(384,n1,n2,o);
    printf("-------\nex-mycall: (%d, %d, %c) \nRetorno da chamada de sistema: %d.\n", n1, n2, o, r);
    
    return 0;
}
