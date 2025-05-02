#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
  int rc = fork();
  if (rc < 0)
  {
    fprintf(stderr, "fork failed\n");
    exit(1);
  }
  else if (rc == 0)
  {
    close(STDOUT_FILENO);
    open("./p4.txt", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);

    char *myargs[3];
    myargs[0] = strdup("ls");
    myargs[1] = strdup("-l");
    myargs[2] = NULL;

    printf("%s\n", myargs[0]);
    printf("%p\n", myargs);

    execvp(myargs[0], myargs);
    printf("This shouldn't print out");
  }
  else
  {
    int rc_wait = wait(NULL);
  }
  return 0;
}