#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <signal.h>

void sighandler(int signum){
  if (signum == SIGINT){
    printf("Program exited due to SIGINT");
    exit(0);
  }
  if (signum == SIGUSR1){
    printf("PID of the parent process: %d\n", getppid());
  }
}

//The argument is the commands
//Returns error when there is one, if works none.
//The function executes the commands inputted.
void execute(char** input){
  if (strcmp(input[0], "exit") == 0)
    exit(0);
  else if (strcmp(input[0], "cd") == 0)
    chdir(input[1]); 
  else {
    int f = fork();
    if (f == -1) {
      exit(1);
    }
    else if(f == 0) {
      /*pipe attempt
      if (strcmp(input[1], "<" == 0)){
	int fdin =open(input[0], O_RDONLY, 0644);
	dup2(fdin, STDIN_FILENO);
	close(fdin);
      }
      if (strcmp(input[1], "<" == 0)){
	int fdin =open(input[2], O_RDONLY, 0644);
	dup2(fdout, STDOUT_FILENO);
	close(fdout);
      }
      */
      if (execvp(input[0], input) < 0) {
	exit(1);
      }
    }
    else {
      int cstat;
      waitpid(f, &cstat,0);
    }
  }
}

/*Intended to be used for getting rid of spaces
  before and after the semicolon.
  Did not work
char * clearSpace(char * input){
  int x = 0;
  if (input[0] == 0){
    while (input[x + 1]){
      char * temp = input[x + 1];
      input[x + 1] = input[x];
      input[x] = temp;
      x++;
    }
  }
  input[x] = NULL;
}*/
		  
int main(){
  char * line;
  line = (char *)malloc(sizeof(256));
  fgets(line, 256, stdin);
  line[strlen(line) - 1] = 0;
  char *commands[100];
  char *command[20];
  int i = 0;
  int x = 0;
  int y = 0;
  while (line){
    commands[i] = strsep(&line, ";");
    i++;
  }
  while (commands[x]){
    while(command[y] = strsep(&commands[x], " ")){
      y++;
    }
    execute(command);
    x++;
  }
  return 0;
}	       
