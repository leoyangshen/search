#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>


void do_work(int num_children, int num1, int num2, pid_t pid) 
{ 
	for (int i = 0; i < num_children; ++i) 
        {
       		pid = fork();
        	if (pid < 0) 
		{
			perror("fork");
			exit(EXIT_FAILURE);
		} 
		// Child process
 		if (pid == 0)
		{
 			printf("Child with pid#%d says: I'm working on task #%d ", getpid(), i + 1);
 			switch (i)
			{
				case 0:
 					printf("Child with pid#%d says: %d + %d = %d\n", getpid(), num1, num2, num1 + num2);
				break;
 				case 1:
 					printf("Child with pid#%d says: %d - %d = %d\n", getpid(), num1, num2, num1 - num2);
 				break;
				case 2:
 					printf("Child with pid#%d says: %d * %d = %d\n", getpid(), num1, num2, num1 * num2);
 				break;
 				case 3:
 					printf("Child with pid#%d says: %d / %d = %d\n", getpid(), num1, num2, num1 / num2);
 				break;
 				default:
 					printf("Child with pid#%d says: I'm a child with no task! :-(\n", getpid());
				break;
			}
			exit(0); // Child exits after its task
		// Parent waits for the specific child to finish
		} else
		{
			waitpid(pid, NULL, 0);
			printf("Parent says: The child with pid#%d has finished!\n\n", pid);
			fflush(stdout);
		}
	}
}
int main() {
    int num;
    printf("How many children do you need? ");
    scanf("%d", &num);

    int n1, n2;
    printf("Enter the first integer number: ");
    scanf("%d", &n1);
    printf("Enter the second integer number: ");
    scanf("%d", &n2);

    pid_t p;
    // int i;

    do_work(num, n1, n2, p);
    return 0;
}
