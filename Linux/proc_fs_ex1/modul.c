#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/cdev.h>
#include <linux/uaccess.h>
//#include <stdio.h>
#include <linux/proc_fs.h>

#define MAX_PROC_SIZE 100
static char proc_data[MAX_PROC_SIZE];
static struct proc_dir_entry *proc_write_entry;

static ssize_t read_proc(struct file *file, char __user *ubuf, size_t count, loff_t *ppos)
{
	printk(KERN_DEBUG "read handler\n");
	return 0;
}

static int my_open(struct inode *inode, struct file *file)
{
	printk(KERN_DEBUG "my open\n");
	return 0;
}
static ssize_t write_proc(struct file *file, const char __user *ubuf, size_t count, loff_t *ppos)
{
        printk( KERN_DEBUG "read handler\n");
	return 0;
}
#if kernel_version
static struct file_operations myops =
{
	.owner = THIS_MODULE,
	.read  = read_proc,
	.write = write_proc,
};
#else
static const struct proc_ops myops = {
	.proc_open = my_open,
	.proc_read = read_proc,
	.proc_write = write_proc,
};
#endif

MODULE_DESCRIPTION("My kernel module");
MODULE_AUTHOR("Me");
MODULE_LICENSE("GPL");

static int dummy_init(void)
{
        pr_debug("Hi\n");
	printk("Hi\n");
	proc_write_entry = proc_create("mydev",0660,NULL,&myops);
        return 0;
}

static void dummy_exit(void)
{
        pr_debug("Bye\n");
	printk("bye\n");
	proc_remove(proc_write_entry);
}

module_init(dummy_init);
module_exit(dummy_exit);

