#include <linux/unistd.h>
#include <linux/linkage.h>
#include <linux/kernel.h>

asmlinkage long sys_mycall(int n1, int n2, char op) {
    int res;
    switch (op) {
        case '+':
            res = n1+n2;
            break;
        case '-':
            res = n1-n2;
            break;
        case '*':
            res = n1*n2;
            break;
        case '/':
            res = n1/n2;
            break;
        default:
            res = 0;
    }

    printk(KERN_INFO "***********\nsyscall: mycall called with (%d, %d, %c) \nso we've got %d%c%d = %d\n", n1, n2, op, n1, op, n2, res);
    return res;
}
