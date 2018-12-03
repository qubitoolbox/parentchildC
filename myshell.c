#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <ctype.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
//maximum arguments size
#define MAXARGS 1024
#define ON 1
#define OFF 0
#define TWO 2

//check when to exit program
int executeshell = ON;
//check when wait is set
int waitset = ON;

// redirection of stdin
void fileIn(char *fil)
{
  //open file as read only
  int filnum = open(fil, O_RDONLY);
  //redirection
  dup2(filnum, fileno(stdin));
  
  close(filnum);
}

//redirection of stdout
 void fileOut(char *fil)
{
  //open file writing
  //if file exists
  int filout = open(fil, O_WRONLY | O_TRUNC | O_CREAT, 0600);
  dup2(filout, fileno(stdout));
  close(filout);
}

void pipeExec(char *cmdline[])
{
  //file containing pipes
  int fd[TWO];
  //init pipe
  pipe(fd);
  //
  dup2(fd[1], fileno(stdout));
  //close end of pipe
  close(fd[1]);
  //run piped programs
  exe(cmdline);
  
  dup2(fd[0], fileno(stdin));
  //close input of pipe
  close(fd[0]);

}

// executes a command.
void exe(char *cmdline[])
{
  //process 
  pid_t pid;

  if (strcmp(cmdline[0], "exit") && strcmp(cmdline[0], "quit")!= 0)
  {
    pid = fork();
    if (pid < 0) 
    { 
      fprintf(stderr, "Fork Failed");
    }
    else if ( pid == 0) 
    { 
      // child process 
      execvp(cmdline[0], cmdline);
    }
    else 
    { 
      // parent process
      if (waitset) 
      {
        waitpid(pid, NULL, 0);

      } 
      else 
      {
        waitset = 0;

      }
    }
    //redirection
    // '/dev/tty' represents current process
    fileIn("/dev/tty");
    fileOut("/dev/tty");
  }
  else 
  {
    //end shell
    executeshell = OFF;
  }
}

// Creates a tokenized form of the input with spaces to separate words. 
char *tokparam(char *usrinput)
{
  int i;
  int j;
  j = 0;
  char *tokenize = (char *)malloc((MAXARGS * 2) * sizeof(char));
  // add spaces to special characters
  for (i = 0; i < strlen(usrinput); i++) 
  {
    if (usrinput[i] != '|' && usrinput[i] != '<' && usrinput[i] != '>') 
    {
      tokenize[j++] = usrinput[i];

    } 
    else 
    {
      tokenize[j++] = ' ';
      tokenize[j++] = usrinput[i];
      tokenize[j++] = ' ';
    }
  }
  tokenize[j++] = '\0';

  // add null to end
  char *lastring;
  lastring = tokenize + strlen(tokenize) - 1;
  lastring--;
  *(lastring + 1) = '\0';

  return tokenize;
}

int main(void)
{
  char *cmdline[MAXARGS]; // command line cmdluments
  // excute the shell
  // executeshell can trigger program exit
  while (executeshell) 
  {
    //print menu string
    printf("COP4338$ ");
    fflush(stdout);

    char input[MAXARGS];
    fgets(input, MAXARGS, stdin);

    char *tokens;
    tokens = tokparam(input);

    if (tokens[strlen(tokens) - 1] == '&') 
    {
      waitset = OFF;
      tokens[strlen(tokens) - 1] = '\0';
    }
    // get commands
    char *cmdl; 
    cmdl = strtok(tokens, " ");
    int i = 0;
    while (cmdl) 
    {
      if (*cmdl == '<') 
      {
        fileIn(strtok(NULL, " "));

      } 
      else if (*cmdl == '>') 
      {
        fileOut(strtok(NULL, " "));

      } 
      else if (*cmdl == '|') 
      { 
        cmdline[i] = NULL;

        pipeExec(cmdline);

        i = 0;
        } 
        else 
        {
          cmdline[i] = cmdl;
          i++;
        }
          cmdl = strtok(NULL, " ");
      }
      cmdline[i] = NULL;
      //run commands
      exe(cmdline);
  }
  return 0;
}
