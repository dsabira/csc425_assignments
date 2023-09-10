
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
int main() {
    int rc = fork(); 
    if (rc < 0) {
        exit(1);
    }else if (rc == 0) { 
        printf("This is the child with (PID %d)\n", getpid());
    } else {
	int status;
        int rc_wait = waitpid(rc,&status, 0);
        printf("This is the parent waiting for the child (PID %d)\n", rc);
	printf("Parent process (PID %d) is done\n", rc_wait);

    }

    return 0;
}
