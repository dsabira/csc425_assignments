#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
int main() {
    int rc = fork(); 
    if (rc < 0) {
        exit(1);
    }else if (rc == 0) { 
        printf("This is the child (1) \n");

    } else { // This code will be executed by the parent process
    printf("This is the parent (2) \n");
	int rc_wait = wait(NULL);
	printf("This is the parent after waiting for the child (3) \n");
    }

    return 0;
}
