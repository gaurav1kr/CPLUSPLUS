#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{
    pid_t pid_cur = getpid() ;
    pid_t pid_fork = fork();
  
    printf("pid_cur = %d pid_fork = %d\n",pid_cur , pid_fork);
    return 0;
}
