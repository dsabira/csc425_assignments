#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int rc = fork();
    if (rc < 0) {
        exit(1);
    }else if (rc == 0) { 
        printf("Child process\n");

    // Using execl()
    execl("/bin/ls", "ls", NULL);

    // Using other variants that are not going to be executed
	printf("Using execl\n");
	execl("/bin/ls", "ls", NULL);
	
	printf("Using execlp\n");
	execlp("ls", "ls", NULL);

	printf("Using execv\n");
	char *argv[] = {"ls", NULL};
	execv("/bin/ls", argv);
	
	printf("Using execvpe\n");
	execvp("ls", argv);
	

    } else { 
        printf("Parent process\n");
    }

    return 0;
}
