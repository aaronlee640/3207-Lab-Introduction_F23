#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef char c;
c randchar()
{
    int randomInt = rand() % 26 + 'a';

    char c = (char)randomInt;
    
    return c;
}