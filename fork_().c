#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
//constants
typedef int bool;
#define true 1;
#define false 0;

int main()
{
  
  //process ID
  pid_t pid;

  int j;
  pid = fork();
  bool start = true;
      
  do
  {
        
    if(pid > 0 && j < 100)
    {
      start = true;
      j++;
      printf("\t\t\tPARENT %d\n", j);
    }
    else
    {
          
      if (j > 100)
      {
          
        start = true;
      }
        j++;
        printf("CHILD %d\n", j);
     }      
      
    }while(!(start));
    
    return (0);
    }

}
