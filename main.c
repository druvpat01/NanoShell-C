#include "my_shell.h"

//shell loop
// Input Parsing
// Command Execution
// Handle Built-in commands exp., cd, pwd, echo, env, setenv, unsetenv, which, exit
// Execute external commands
// Manage environment variables
// Manage Path
// Error Handling

void shell_loop(char** env){
    /*  This is the shell loop */

    char* input = NULL;     // pointer to the char   
    size_t input_size = 0;      // size_t: unsigned integer, only hold non-negative values (0 and positive integers)

    char** args;        // pointer to pointer to char

    while(1){
        printf("[my_shell]>");

        if(getline(&input, &input_size, stdin) == -1)    // End of the File (EOF), Cltr + D
        {
        //  perror("getline");
         break;   
        }

        // getline(&input, &input_size, stdin);

        // printf("Input: %s",input);

        args = parse_input(input);

        printf("Args: ");
        for(size_t i=0; args[i]; i++)
            printf("%s\n", args[i]);
    }
}


// char** env : will give us the environment we will work on
int main(int argc, char** argv, char** env){

    // as we dont need argc, argv
    (void)argc;
    (void)argv;

    shell_loop(env);

    return 0;
}