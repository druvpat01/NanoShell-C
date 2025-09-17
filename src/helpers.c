#include "my_shell.h"


int my_strcmp(const char* str1, const char* str2){
    /*
        returns:
            0 : if the strings are equal
            <1 : str1 < str2
            >1 : str1 > str2
    */

    while (*str1 && (*str1 == *str2))
    {
        str1++;
        str2++;
    }


    return *(unsigned char*)str1 - *(unsigned char*)str2;
}


int my_strlen(char* str){
   /* returns the length of the string */
   size_t len = 0;

   while(*str){
    len++; str++;
   }
   return len;
}


int my_strncmp(char* str1, char* str2, size_t n){
    /*
        returns:
            0 : if strings are equal to n characters
            <0: if str1 < str2 in the first n characters
            >0: if str1 > str2 in the first n characters
    */

    size_t i = 0;

    while (i < n && str1[i] && str2[i]){
        if (str1[i] != str2[i])
            return (unsigned char)str1[i] - (unsigned char)str2[i];
        i++;
    }

    if (i == n)
        return 0;
    
    return (unsigned char)str1[i] - (unsigned char)str2[i];
}


char* my_getenv(char* name, char** env){
    if (name == NULL || env == NULL)
        return NULL;

    size_t name_len = my_strlen(name);

    for (size_t i=0; env[i]; i++){
        // Check if the curr env var starts with 'name='
        if (my_strncmp(env[i], name, name_len) == 0 && env[i][name_len] == '=')
            return &env[i][name_len+1];
    }
    return NULL;
}