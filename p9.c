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
    open("./p9.txt", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
    printf("This is child printing");
  }
  else
  {
    printf("This is parent printing");
  }
  return 0;
}