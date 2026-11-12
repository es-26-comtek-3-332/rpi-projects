#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/stat.h>
// Add license stuff here
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Tobias N. Jensen");
MODULE_DESCRIPTION("A simple Hello World module");

// Add parameter list here
static int __init eksempel_init(void) {
    printk(KERN_INFO ”Hellow world !\n”);
    return 0;
}
static void __exit eksempel_exit(void) {
    printk(KERN_INFO “Goodbye cruel world !\n”);
}
module_init(eksempel_init);
module_exit(eksempel_exit);