

*********************************************
   Your name:Sabira Duishebaeva
   - **Question 1:** <Both of the updated but they do it separately because they are 2 different processes.>
   - **Question 2:** <Yes, both parent and child can access the file descriptor. If we keep the wait, the child writes to a file first and then the parent. And if we remove wait, the parent writes first.  >
   - **Question 4:** <Different variants of the `exec()` function exist for flexibility and convenience, accommodating diverse needs in passing arguments, locating executables, and handling environment variables in various use cases.>
   - **Question 5:** <The output will depend on the environment. But no matter what the 3 (refer to code) will never be printed before 1 despite the fact that they are in different conditional statements because of wait(). If we declare wait inside child process the result is an error as the child process has no other process to wait for.>
   - **Question 6:** <Waitpid() comes in handy when dealing with multiple child processes that are terminating. It allows us to retrieve and check the exit status of a specific child by using its PID after it has completed execution>
   - **Question 7:** <It is not going to print anything because you close the standard output file descriptor and it will have no effect on printf. 
*********************************************
