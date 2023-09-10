#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {
  int file = open("file.txt", O_CREAT | O_RDWR, S_IRWXU); //Obtained the permission S_IRWXU from ChatGPT 
  if (file <0 ) {
    perror("Error open");
    exit(1);
  }

  int rc = fork();

  if (rc < 0) {
    fprintf(stderr, "fork failed\n");
    exit(1);
  } else if (rc == 0) {
    printf("Child writing to a file\n");
    write(file, "Child writing to a file \n", 24);
  } else {
    printf("Parent writing to a file\n");
    write(file, "Parent writing to a file \n", 25);
  }

  close(file);
  return 0;
}
