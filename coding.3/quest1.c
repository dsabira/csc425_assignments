#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
int main() {
    int x_num = 100;

    int rc = fork();

    if (rc < 0) {
        perror("forking child failed");
        exit(1);
    }

    else if (rc == 0) {
        x_num = x_num + 10;
        printf("Child process: updated x_num = %d\n", x_num);
    } else {
        // This is the parent process
        x_num = x_num + 50; 
        printf("Parent process: updated  x_num  = %d\n", x_num);
    }

    return 0;
}
