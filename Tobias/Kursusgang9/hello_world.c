#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/stat.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Tobias N. Jensen");
MODULE_DESCRIPTION("A simple Hello World module");

static char mychar = 'T';
static int myint = 22;
MODULE_PARM_DESC(mychar, "A character");
module_param(mychar, char, S_IRUSR);
MODULE_PARM_DESC(myint, "An integer");
module_param(myint, int, S_IRUSR);

static int __init eksempel_init(void) {
    printk(KERN_INFO "Hello world !\n");
    printk(KERN_INFO "mychar is a character: %c\n", mychar);
    printk(KERN_INFO "myage is an integer: %d\n", myint);
    return 0;
}

static void __exit eksempel_exit(void) {
    printk(KERN_INFO "Goodbye cruel world !\n");
}

module_init(eksempel_init);
module_exit(eksempel_exit);
