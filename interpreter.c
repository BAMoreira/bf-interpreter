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

    for (i = 0; in[i] != '\0' && in[i] != EOF; ++i)
    {
        read = in[i];

        if (read == '>')
        {
            ++ptr;
        }
        else if (read == '<')
        {
            --ptr;
        }
        else if (read == '+')
        {
            ++*ptr;
        }
        else if (read == '-')
        {
            --*ptr;
        }
        else if (read == '.')
        {
            putchar(*ptr);
        }
        else if (read == ',')
        {
            *ptr=getchar();
        }
        else if (read == '[')
        {
            if (*ptr)
                continue;
            else
            {
                loop = 1;
                while (loop > 0)
                {
                    read = in[++i];
                    if (read == ']')
                        loop--;
                    else if (read == '[')
                        loop++;
                }
            }
        }
        else if (read == ']')
        {
            if (*ptr)
            {
                loop = 1;
                while (loop > 0)
                {
                    read = in[++i];
                    if (read == '[')
                        loop--;
                    else if (read == ']')
                        loop++;
                }
            }
        }
    }

    return;
}

int main(void)
{
    return EXIT_SUCCESS;
}
