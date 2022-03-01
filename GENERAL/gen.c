#include <stdio.h>
#include <errno.h>
#include <string.h>
#define MAX 10
  
int main ()
{
    FILE *fp;
  
    fp = fopen(" GeeksForGeeks.txt ", "r");
    int i = MAX ;
  
    printf("Value of errno: %d\n ", errno);
    perror("Error =");
  
    return 0;
}
