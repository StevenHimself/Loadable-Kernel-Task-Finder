#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/moduleparam.h>
#include <linux/sched/signal.h> 
#include <linux/string.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Steven Montecinos");
MODULE_DESCRIPTION("This module will find if a specific task is running and report it");

static char *name;
static int flag = 1;

static int __init find_task(void) //starts when module is loaded
{
	printk(KERN_ALERT "Initiating Loadable Kernel Module...\n");
	printk(KERN_ALERT "Process name you have chosen is %s\n", name);
	struct task_struct *task_list;
	
	for_each_process(task_list) {		//goes through the list of running processes within the task list	
			
		if(!strncmp(task_list->comm , name, strlen(name))){		//checks if the process name chosen is running
			printk(KERN_ALERT "Found process %s with pid %i\n" , name, task_list->pid);
			flag = 0;
		}	
	}
	if(flag){
		printk(KERN_ALERT "Unable to find process %s\n", name);
	}
	return 0;
}

static void __exit find_task_exit(void) //exits when module is unloaded
{
	printk(KERN_ALERT "Exiting Loadable Kernel Module...\n");
}

module_init(find_task);
module_exit(find_task_exit);
module_param(name, charp, S_IRUGO);

