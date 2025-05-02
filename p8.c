#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
  int testValue = 100;
  printf("Original value %d\n", testValue);

  int rc = fork();

  if (rc < 0)
  {
    fprintf(stderr, "fork failed\n");
    exit(1);
  }
  else if (rc == 0)
  {
    // int rc_wait = wait(NULL);
    printf("value in child %d\n", testValue);
    testValue = 200;
    printf("value in child modified %d\n", testValue);
  }
  else
  {
    int status;
    // int rc_wait = wait(NULL);
    while (1)
    {
      int result = waitpid(rc, &status, WNOHANG);
      if (result != 0)
      {
        testValue = 300;
        printf("value in parent modified %d\n", testValue);
        break;
      }
    }
  }
  // printf("Parent %d\n", getpid());
  // printf("Child %d\n", rc);
  return 0;
}