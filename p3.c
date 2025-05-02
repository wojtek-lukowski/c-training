#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
  printf("hello (pid:%d)\n", (int)getpid());
  int rc = fork();

  if (rc < 0)
  {
    fprintf(stderr, "fork failed\n");
    exit(1);
  }
  else if (rc == 0)
  {
    printf("child (pid:%d)\n", (int)getpid());
    char *myargs[3];
    myargs[0] = strdup("wc");
    myargs[1] = strdup("p3.c");
    myargs[2] = NULL;

    printf("%s\n", myargs[0]);
    printf("%p\n", myargs);

    execvp(myargs[0], myargs);
    printf("This shouldn't print out");
  }
  else
  {
    int rc_wait = wait(NULL);
    char *test[3];
    test[0] = "test0";
    test[1] = "test1";
    test[2] = "test2";

    printf("%s\n", test[0]);
    printf("%p\n", test[0]);

    printf("parent of %d (rc_wait:%d) (pid:%d)\n",
           rc, rc_wait, (int)getpid());
  }
  return 0;
}