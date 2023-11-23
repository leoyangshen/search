#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {
    int num_children;
    printf("How many children do you need? ");
    scanf("%d", &num_children);

    int num1, num2;
    printf("Enter the first integer number: ");
    scanf("%d", &num1);
    printf("Enter the second integer number: ");
    scanf("%d", &num2);

    pid_t pid;
    int i;

    for (i = 0; i < num_children; ++i) {
        pid = fork();
        if (pid < 0) {
            perror("fork");
            exit(EXIT_FAILURE);
        }

        // Child process
        if (pid == 0) {
            printf("Child with pid#%d says: I'm working on task #%d ", getpid(), i + 1);
            switch (i) {
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
        } else {
            // Parent waits for the specific child to finish
            waitpid(pid, NULL, 0);
            printf("Parent says: The child with pid#%d has finished!\n\n", pid);
        }
    }

    return 0;
}
