#include <string.h> 
#include <ctype.h>
#include "parser.h"


#include <stdlib.h>
#include <stdio.h>


char *my_strtrimlead(char *string)
{
    for (/* empty */; isspace(*string) || *string == '\0'; ++string)
    {
        // Empty
    }

    return string;
}

