#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

int error = 0;
long int x;

typedef struct 
{
    long int head, tail;
    long int size[MAX];
}Queue;

Queue *Q;

void ENQUEUE(Queue *Q, int x)
{
    if ( Q->head == Q->tail + 1 || ( Q->head == 0 && Q->tail == MAX - 1 ))
    {
        error = error + 1;
    }
    else
    {
        if ( Q->head == -1 )
        {
            Q->head = 0;
        }
        Q->tail =  ( Q->tail + 1) % MAX;
        Q->size[Q->tail] = x;
        }  
    }  

int DEQUEUE(Queue *Q)
{
    if ( Q->tail == -1)
    {
        error = error + 1;
        return 0;
    }
    else
    {
        x = Q->size[Q->head];
        {
            if (Q->head == Q->tail)
            {
                Q->head = -1;
                Q->tail = -1;
            }
            else
            {
                Q->head = ( Q->head + 1 ) % MAX;
            }

            return x;      
        }
    }    
}

int DISPLAY(Queue *Q)
{
    if ( error > 0)
    {
        printf("error\n");
    }
    else
    {
        int i;

        for ( i = Q->head; i != Q->tail; i = (i + 1) % MAX )
        {
            printf("%ld\n", Q->size[i]);

        }
        printf("%ld\n", Q->size[i]);

    }

    return 0;
}


int main()
{

    char str[20];

    Q=(Queue*)malloc(sizeof(Queue));
    Q->head = -1;
    Q->tail = -1;

    while ((strcmp("END", str) != 0))
    {
        scanf("%s", str);

        if (strcmp("ENQUEUE", str) == 0)
        {
            scanf("%ld", &x);
            ENQUEUE(Q,x);
        }

        else if (strcmp("DEQUEUE", str) == 0)
        {
            DEQUEUE(Q);
        }
    }

    DISPLAY(Q);

    free(Q);
    
    return 0; 
}
