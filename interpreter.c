/* Exercise 10: Brain Force
 * Author: Bernardo de Azevedo Moreira
 * Date: 31/05/2017
 *
 * DISCLAIMER: This program comes with no warranty whatsoever: use and modify it at your own risk
 */

#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

#define INSIZE 1024

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
            /* char version: */
            /* putchar(*ptr); */
            printf("%d\n",*ptr);
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
                    read = in[--i];
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
    char in[INSIZE] = {0};
    if (fgets(in, INSIZE, stdin) != NULL)
        interpret(in);
    
    return EXIT_SUCCESS;
}
