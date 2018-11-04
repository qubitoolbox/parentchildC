#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
  
  //process ID
  pid_t pid;

    int j;
    pid = fork();
    if ( pid > 0)
    {
      bool start = true;
      
      do
      {
      
        
        
        if(pid > 0)
        {
        
          j++;
          printf("\t\t\tPARENT %d\n", j);
     
        }
        else
        {
        
          j++;
          printf("CHILD %d\n", i);
        
        }
      
      
      }while(!(start));
    
      return (0);
    
    }








}
