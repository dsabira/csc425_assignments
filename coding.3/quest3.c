

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main() {
    int rc = fork();
    if (rc < 0) {
        exit(1);
    } else if (rc == 0) {
        printf("Hello\n");
    } else {
	sleep(5);
    printf("Goodbye\n");
    }
    return 0;
}
