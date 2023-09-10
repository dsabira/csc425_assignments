
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
int main() {
    int rc = fork(); 
    if (rc < 0) {
        exit(1);
    }else if (rc == 0) { 
        printf("This is the child \n");
	close(STDOUT_FILENO);
	printf("Child process continues here \n");
    } else { 
	printf("This is the parent waiting for the child \n");
        int rc_wait = wait(NULL);
	printf("Parent is done\n");
    }

    return 0;
}
