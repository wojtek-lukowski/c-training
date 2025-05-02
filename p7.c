#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <fcntl.h>

int main()
{
  pid_t pid = fork();

  if (pid == 0)
  {
    printf("Hello %d\n", getpid());
  }
  else
  {
    int status;

    while (1)
    {
      pid_t result = waitpid(pid, &status, WNOHANG);
      if (result == 0)
      {
        // sleep(1);
        printf("status %d\n", status);
      }
      else
      {
        printf("Good bye %d\n", getpid());
        printf("status %d\n", status);
        break;
      }
    }
  }
  return 0;
}