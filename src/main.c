#include "my_shell.h"

//shell loop
// Input Parsing
// Command Execution
// Handle Built-in commands exp., cd, pwd, echo, env, setenv, unsetenv, which, exit
// Execute external commands
// Manage environment variables
// Manage Path
// Error Handling


// cd, pwd, echo, env, setenv, unsetenv, which, exit
int shell_builts(char** args, char** env, char* initial_dir){
    (void)env;
    (void)initial_dir;
    /* Handling built in commands*/
    printf("Args[0]: %s\n", args[0]);
    if(my_strcmp(args[0], "cd") == 0){
        printf("CD\n");
    }
        // return command_cd(args, intital_dir);

    else if(my_strcmp(args[0], "pwd") == 0){
        printf("PWD\n");
    }
        // return command_pwd();

    else if(my_strcmp(args[0], "echo") == 0){
        printf("ECHO\n");
    }
        // return command_echo(args, env);

    else if(my_strcmp(args[0], "env") == 0){
        printf("ENV\n");
    }
        // return command_env(env);
    
    else if(my_strcmp(args[0], "setenv") == 0){
        printf("SETENV\n");
    }
        // return command_setenv(args, env);

    else if(my_strcmp(args[0], "unsetenv") == 0){
        printf("UNSETENV\n");
    }
        // return command_unsetenv(args, env);

    else if(my_strcmp(args[0], "which") == 0){
        printf("WHICH\n");
    }
        // return command_which(args, env);

    else if(my_strcmp(args[0], "exit") == 0 || my_strcmp(args[0], "quit" ) == 0){
        printf("I am exiting!");
        exit(EXIT_SUCCESS);
    }
    else{}
        // return;
        // NOT A BUILT-IN COMMAND
    
    // exit(EXIT_SUCCESS);
    return 0;
}

void shell_loop(char** env){
    /*  This is the shell loop */
    char* input = NULL;     // pointer to the char   
    size_t input_size = 0;      // size_t: unsigned integer, only hold non-negative values (0 and positive integers)

    char** args;        // pointer to pointer to char

    char* initial_dir = getcwd(NULL, 0);
    while(1){
        printf("[my_shell]>");

        if(getline(&input, &input_size, stdin) == -1)    // End of the File (EOF), Cltr + D
        {
         perror("getline");
         break;   
        }

        // getline(&input, &input_size, stdin);

        // printf("Input: %s",input);

        args = parse_input(input);

        // printf("Args: ");
        // for(size_t i=0; args[i]; i++)
        //     printf("Args: %s\n", args[i]);

        if(args[0])   // if args is not NULL
            shell_builts(args, env, initial_dir);
    }

    free_tokens(args);
}


// char** env : will give us the environment we will work on
int main(int argc, char** argv, char** env){

    // as we dont need argc, argv
    (void)argc;
    (void)argv;

    shell_loop(env);

    return 0;   // 0 or EXIT_SUCCESS (a macro defined in <stdlib.h>) indicates successful program execution.
}