#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {
  int pipefd[2];

  if (pipe(pipefd) == -1) {
     perror("pipe failed");
     exit(1);
  }

  pid_t pid1 = fork();

  if (pid1 == 0) {
    // First child will Read and send data to the pipe
    close(pipefd[0]);
    dup2(pipefd[1], STDOUT_FILENO); // Redirect stdout to the pipe
    execlp("cat", "cat", "file.txt", NULL);
  } else {
    pid_t pid2 = fork();

    if (pid2 == 0) {
      // Second child will  Receive data from the pipe and count words
      close(pipefd[1]);
      dup2(pipefd[0], STDIN_FILENO);
      fprintf(stderr, "the number words in file.txt: ");
      execlp("wc", "wc", "-w", NULL); // Count words in the input
    } else {
      close(pipefd[0]);
      close(pipefd[1]);
      int status;
      waitpid(pid2, &status, 0);
    }
  }

  return 0;
}
