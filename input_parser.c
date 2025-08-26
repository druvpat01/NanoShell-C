#include "my_shell.h"


char** parse_input(char* input){
    /* parses the input
        eg: 'echo -r --name $Path'
        parsee input: ['echo', '-r', '--name', '$Path']  
    */

    size_t buffer_size = MAX_INPUT;    
    char** tokens = malloc(buffer_size * sizeof(char*));    // allocating space for tokens: returns NULL if space is not allocated
    char* token = NULL;
    size_t position = 0;
    size_t token_length = 0;

    // raising error if malloc fails to allocate space to tokens
    if(!tokens){
        perror("Malloc");
        exit(EXIT_FAILURE); 
        
    }

    for(size_t i=0; input[i]; i++)
    {
        // storing the starting address of the token
        token = &input[i];

        // fetching the token length till we encounter whitespace or end of array
        while(input[i] && input[i]!= ' ')
        {
            token_length++;
            i++;
        }

        // getting  space for each token
        tokens[position] = malloc((token_length+1) * sizeof(char));
        
        if(!tokens[position]){
            perror("Malloc");
            exit(EXIT_FAILURE);
        }

        // storing each 
        for(size_t j=0; j<token_length; j++){
            tokens[position][j] = token[j];
        }

        tokens[position][token_length] = '\0';  // NULL terminate token
        position++;
        token_length = 0;   // reset for the next token
    }

    tokens[position] = NULL;    // Terminate the array with NULL
    return tokens;
}   