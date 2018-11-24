#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
/*Return 1 if i'th bit of n is 1; 0 otherwise*/

#define EXTRACT_BIT(n,i) ((n&(1<<i))?1:0)

void check_circuit (int id, int z)
{
  int v[16] ; //each element is a bit of z
  int i;
  
  for (i = 0l i < 16; i++) v[i] = EXTRACT_BIT(z,i);
  
  if ((v[0] || v[1]) && (!v[1] || !v[3]) && (v[2] || v[3])
   



}

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
