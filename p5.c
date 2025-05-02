#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
  int testValue = 100;
  int rc = fork();
  if (rc < 0)
  {
    fprintf(stderr, "fork failed\n");
    exit(1);
  }
  else if (rc == 0)
  {
    printf("value in child %d\n", testValue);
    testValue = 200;
    printf("value in child modified %d\n", testValue);
  }
  else
  {
    int rc_wait = wait(NULL);
    testValue = 300;
    printf("value in parent modified %d\n", testValue);
  }
  return 0;
}