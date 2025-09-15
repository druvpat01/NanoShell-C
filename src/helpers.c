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