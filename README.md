# Loadable-Kernel-Task-Finder
A task finder written in kernel space to detect if a process is running within your Linux environment. If so, it display the existing process along with its process ID in the kernel log. 

# Running the Project
1. Open the Linux terminal and git clone this repository into a directory of your choosing
2. Navigate to the directory in which the repository is saved in
3. Enter ```run Make``` or ```Make``` in the command line to build your kernel object and other required resource files
4. Enter the ```ls``` command to ensure the makefile built and generated the files properly
5. Load the kernel module by entering ```sudo insmod findTask.ko [name=process-name]```
6. Open a separate terminal window and run ```tail -f /var/log/kern.log``` to get access to the kernel log
7. Check the kernlog to determine if the ```process-name``` argument is running
8. Remove the kernel module/object by enter ```sudo rmmod findTask.ko```

# Project Output 
If all of the steps are performed correctly, the kernel log should display the expected progam output. In the case below, the passed ```process-name``` argument is **bash**. According to the kernel log, this process is running in the background. Therefore, it will output that the process was found along with its process ID.

![taskFinderOutput](https://user-images.githubusercontent.com/90062442/222931884-e8b947e5-4fc8-47a3-bb37-19ebacabf12d.JPG)
