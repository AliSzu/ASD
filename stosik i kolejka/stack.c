#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

int error =0;

typedef struct
{
    long int top;
    long int size[MAX];

}Stos;

Stos *S;

int STACK_EMPTY(Stos *S)
{
   return S->top == -1;
    
}


void PUSH(Stos *S, int x)
{

    if ( S->top == MAX -1 )
    {
        error++;
    }
    else
    {
        S->top = S->top + 1;
        S->size[S->top] = x;
    }
}

int POP(Stos *S)
{
    if (STACK_EMPTY(S))
    {
        error++;
    }
    else
    {
        S->top = S->top -1;
        return S->size[S->top + 1];
    }   

    return 0;
}

int DISPLAY(Stos *S)
{
    if ( S->top == -1)
    {
        error++;
    }
    else
    {
        for ( int i=S->top; i>=0; i--)
        {
            printf("%ld\n", S->size[i]);
        }
    }

    return 0;
    
}

int main()
{
    char str[20];
    long int x;

    S=(Stos*)malloc(sizeof(Stos));
    S->top=-1;


    while ((strcmp("END", str) != 0))
    {
        scanf("%s", str);

        if (strcmp("PUSH", str) == 0)
        {
            scanf("%ld", &x);
            PUSH(S,x);
        }
        else if (strcmp("POP", str) == 0)
        {
            POP(S);
        }
    }

    if ( error > 0)
    {
        printf("error\n");
    }
    else
    {
         DISPLAY(S);
    }
    

     return 0;
      
}
