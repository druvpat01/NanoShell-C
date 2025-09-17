#include "my_shell.h"


// cd, cd [path], cd - (previous dir), cd ~ (home dir), handle non-existing dirs, permission issues
int command_cd(char** args, char* initial_dir){
    (void)initial_dir;

    if (args[1] == NULL)
        printf("cd: expected argument \"cd [path]\"\n");
    else if (chdir(args[1]) == 0)
        printf("cd worked!\n");
    else    
        perror("CD");
    
    return 0;
}


int command_pwd(){
   char* cwd = NULL;

   // Use dyamic allocation
   cwd = getcwd(NULL,0);
   
   if (cwd != NULL){
        // printf("%s\n",cwd);  
        free(cwd);
   }
   else 
        perror("getcwd");

   return 0;
}


// echo Hello World, echo -n Hello World, echo $Path
int command_echo(char** args, char** env){
    int newline = 1;    // default echo ends with newline
    size_t i = 1;       // skipping the -n
    
    // Checking for newline flag
    if(args[1] != NULL && my_strcmp(args[1],"-n") == 0){
        newline = 0;
        i++;
    }

    // process remaining args
    for(; args[i]; i++){
        if (args[i][0] == '$'){ // Hanlding the env varibles
            char* value = my_getenv(args[i]+1, env);    // skip the $ sign and get the variables

            if (value)
                printf("%s", value);
            else
                printf("Invalid env variable!");
        }
        else
            printf("%s", args[i]);
        
        if (args[i+1] != NULL)
            printf(" ");
        
        // if(args[i+1] == NULL && newline)
        //     printf("\n");
    }

    if (newline)
        printf("\n");
    
    return 0;
}


int command_env(char** env){
    size_t index = 0;

    while (env[index]){
        printf("%s\n",env[index]);
        index++;
    }
    return 0;
}


int command_which(char** args, char** env);