#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
//add necessary libraries for functions

int main(){
  char * line;
  line = (char *)malloc(sizeof(256));
  fgets(line, 256, stdin);
  line[strlen(line) - 1] = 0;
  char *commands[100];
  char **command[20];
  int i = 0;
  int x = 0;
  int y = 0
  while (line){
    commands[i] = strsep(&line, ";");
    i++;
  }
  while (commands[x]){
    while(commands[x]){
      command[y] = strsep(commands[x], " ");
      y++;
    }
    //code to execute the command
    /*for example,
    commands[i] = NULL;
    execvp(commands[0],commands);
    also include pipe and redirection stuff in seperate functions on top.
    remember command[0] can be cd or exit.
    */
    x++;
  }
  return 0;
}
		  
