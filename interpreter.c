#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

void interpret(char* in)
{
    unsigned char mem[30000] = {0}; /* memory space for pointer */
    unsigned char* ptr = mem; /* the pointer itself */
    
    char read;      /* char being read */

    size_t i;       /* size_t is apparently more adequate to */
    size_t loop;    /* control unsigned arrays and pointers  */

    for (i = 0; in[i] != '\0' && in[i] != EOF; i++)
    {
        
    }

    return;
}

int main(void)
{
    return EXIT_SUCCESS;
}
