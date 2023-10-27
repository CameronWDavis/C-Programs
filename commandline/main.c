#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(void) {
  //variables
  char input[100]; 
  char *command,*argument1, *argument2;
  printf("Type Ctrl-C to exit\n"); 
  //while loop will go to control c
  while(true){
   //print new line and the option for user input 
  printf("\n");
  printf("$>");
  scanf("%[^\n]%*c",input); //this statement uses a string formatter to read in the user input
    
    //tokenizing the string into its required variables
    command = strtok(input," ");
    argument1 = strtok(NULL," ");
    argument2 = strtok(NULL," ");
    

  if(strcmp(command,"dir") == 0){
    if(argument1 != NULL){
      printf("To many arguments!");
    }else{
      system("ls -l");
      continue;
    }
  }//end dir
    //start of type
  else if(strcmp(command,"type") == 0){
    char catCommand[100];
    if(argument1 == NULL){
      printf("To few arguments"); 
    }else if(argument2 == NULL){
          sprintf(catCommand,"cat %s",argument1);
          system(catCommand);
      continue;
    }
      else if(strcmp(argument1,"-n") == 0 && argument2 != NULL){
        sprintf(catCommand,"cat %s %s",argument1,argument2);
        system(catCommand);
        continue;
      }
    else if(argument2 != NULL){
      sprintf(catCommand,"cat %s %s",argument1,argument2);
      system(catCommand);
      printf("\n");
      }
    else{
      printf("Sorry not Valid!"); 
    }
  }//end type statements
    //start of rename statement
  else if (strcmp(command,"ren") == 0){
    //local variable
    char mvCommand[100];
    if(argument1 == NULL || argument2 == NULL){
      printf("Error not enough arguments for ren");
    }else{
      sprintf(mvCommand,"mv %s %s",argument1,argument2);//creating the string
      system(mvCommand);
    } //end of rename
    //start of delete
  }else if(strcmp(command, "del") == 0){
    char rmCommand[100];
    if(argument1 != NULL){
    sprintf(rmCommand,"rm %s",argument1);
      system(rmCommand);}else{
      printf("not enought arguments!"); 
      }//end of delete
  }else if(strcmp(command, "copy")== 0){//start of copy
    char cpCommand[100];
    if(argument1 == NULL || argument2 == NULL){
      printf("not enough arguments!");
    }else if(argument1 != NULL && argument2 != NULL){
      sprintf(cpCommand,"cp %s %s",argument1, argument2);
      system(cpCommand); 
    }
  }//end of copy
    else if(strcmp(command,"cd") == 0){
      chdir(argument1); 
    } else if (strcmp(command,"pwd") == 0){//start of pwd for testing
      char pwdCommand[100];
      if(argument1 == NULL || argument2 == NULL){
        system(command);
      }//end of pwd
    }
  else{
    printf("invalid!"); 
  }//end 
  
    }//end while
   
  return 0;
}
