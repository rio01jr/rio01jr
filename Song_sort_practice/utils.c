#include "utils.h"
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void remove_char_from_end(char * str, char char_to_remove){
    if(str[strlen(str) - 1] == char_to_remove){
        str[strlen(str) - 1] = 0;
    }
}

char *string_tolower(const char *str){
    if(str == NULL){
        return NULL;
    }

    size_t len = strlen(str);
    char *newstr = malloc((len+1) * sizeof(char));

    for (size_t i = 0; i < len; i++){
        newstr[i] = tolower(str[i]);
    }
    newstr[len] = '\0';
    return newstr;
}
