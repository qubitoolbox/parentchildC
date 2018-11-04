#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

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
        
        if(pid > 0 && < 100)
        {
          start = false;
          j++;
          printf("\t\t\tPARENT %d\n", j);
     
        }
        else
        {
          
          if (if pd > 100)
          {
          
            start = true;
          
          
          }
          start = false;
          j++;
          printf("CHILD %d\n", i);
        
        }
      
      
      }while(!(start));
    
      return (0);
    
    }








}
