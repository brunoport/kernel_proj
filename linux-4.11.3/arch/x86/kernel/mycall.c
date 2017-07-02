#include <linux/unistd.h>
#include <linux/linkage.h>
#include <linux/kernel.h>

#define MULT 0
#define DIV 1
#define ADD 2
#define SUB 3

asmlinkage long sys_mycall(char *msg) {
    // char buf[256];
    // long copied = strncpy_from_user(buf, msg, sizeof(buf));
    // if (copied < 0 || copied == sizeof(buf))
    //   return -1;
    int i, n1, n2, operation, res;
    int operand = 0;
    for (i = 0; i < sizeof(msg); i++) {
        if (msg[i] == '*') {
            operation = MULT;
            operand = 1;
        } else if (msg[i] == '/') {
            operation = DIV;
            operand = 1;
        } else if (msg[i] == '+') {
            operation = ADD;
            operand = 1;
        } else if (msg[i] == '-') {
            operation = SUB;
            operand = 1;
        } else if (operand == 0) {
            n1 = msg[i]-48;
        } else {
            n2 = msg[i]-48;
        }
    }

    switch (operation) {
        case MULT:
            res = n1*n2;
            break;
        case DIV:
            res = n1/n2;
            break;
        case ADD:
            res = n1+n2;
            break;
        case SUB:
            res = n1-n2;
            break;
    }

    printk(KERN_INFO "mycall called with \"%s\" wich equals %d\n", msg, res);
    return res;
    // return(4096);
}
