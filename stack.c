#include <stdio.h>
#include <stdlib.h>

#define null NULL
#define endl printf ( "\n" )

struct Stack
{
    int capacity;
    int length;
    int * data;

    void ( * push ) ( struct Stack *, int );
    int ( * pop ) ( struct Stack * );
    void ( * dup ) ( struct Stack * );
    void ( * swap ) ( struct Stack * );
    void ( * print ) ( struct Stack * );
    void ( * freeStack ) ( struct Stack * );
};

typedef struct Stack * Stack;

Stack builder ( int );
void push ( Stack, int );
int pop ( Stack );
void dup ( Stack );
void swap ( Stack );
void print ( Stack );
void freeStack ( Stack );

Stack builder ( int capacity )
{
    Stack stack =  malloc ( 1 * sizeof ( struct Stack ) );

    if ( stack == null )
    {
        return null;
    }

    stack -> capacity = capacity;
    stack -> length = 0;
    stack -> data = malloc ( capacity * sizeof ( int ) );
    stack -> push = push;
    stack -> pop = pop;
    stack -> dup = dup;
    stack -> swap = swap;
    stack -> print = print;
    stack -> freeStack = freeStack;

    if ( stack -> data == null )
    {
        free ( stack );
        return null;
    }

    return stack;
}

void push ( Stack stack, int x )
{
    if ( stack -> data != null && stack -> length < stack -> capacity )
    {
        stack -> data [ stack -> length ] = x;
        stack -> length = stack -> length + 1;
    } else
        {
            printf ( "Error to push\n" );
        }
}

int pop ( Stack stack )
{
    int valueToRemove = 0;

    if ( stack -> data != null && stack -> length > 0 )
    {
        stack -> length = stack -> length - 1;
        valueToRemove = stack -> data [ stack -> length ];
        printf ( "\nValor a ser removido : %d\n", valueToRemove );
    } else
        {
            printf ( "Error to pop\n" );
        }
    
    endl;

    return valueToRemove;
}

void dup ( Stack stack )
{
    if ( stack -> data != null && stack -> length <= stack -> capacity )
    {
        int value = stack -> data [ stack -> length - 1 ];
        printf ( "\nValor a ser duplicado : %d\n", stack -> data [ stack -> length - 1 ] );
        stack -> push ( stack, value );
    } else
        {
            printf ( "Error to dup" );
        }
}

void swap ( Stack stack )
{
    if ( stack -> data != null && stack -> length > 1 )
    {
        printf ( "Swaped\n" );
        int x = 0, y = 0;

        x = stack -> pop ( stack );
        y = stack -> pop ( stack );
        stack -> push ( stack, x );
        stack -> push ( stack, y );
    } else
        {
            printf ( "Not swapped" );
        }
}

void print ( Stack stack )
{
    if ( stack -> data != null )
    {
        for ( int i = 0; i < stack -> length; i ++ )
        {
            printf ( "Posicao : [ %d ] -> %d\n", i, stack -> data [ i ] );
        }
    }
}

void freeStack ( Stack stack )
{
    if ( stack -> data != null && stack -> length > 0 )
    {
        free ( stack -> data );
        printf ( "Data stack free\n" );
    } else
        {
            printf ( "Error to free data stack\n" );
        }
}

int main ( )
{
    Stack stack = builder ( 10 );

    // printf ( "Lenght antes do push -> %d\n", stack -> length );

    stack -> push ( stack, 0 );
    stack -> push ( stack, 1 );
    stack -> push ( stack, 2 );

    // printf ( "Lenght depois do push -> %d\n", stack -> length );

    printf ( "\nValores adicionados inicialemnte :\n" );
    stack -> print ( stack );
    endl;

    printf ( "\nTeste pop : \n" );
    stack -> pop ( stack );
    endl;
    stack -> print ( stack );
    printf ( "\nFim teste pop ...\n" );
    endl;

    printf ( "Adicionando novos valores :\n" );

    for ( int i = 3; i <= 10; i ++ )
    {
        stack -> push ( stack, i );
    }

    endl;
    stack -> print ( stack );
    printf ( "\nFim adicionando novos valores ...\n" );
    endl;

    // stack -> push ( stack, 10 );
    // stack -> print ( stack );
    // endl;

    printf ( "Teste adicinando falor acima do limite do tamanho da capacidade :\n" );
    stack -> push ( stack, 11 );
    stack -> print ( stack );
    endl;

    stack -> pop ( stack );
    stack -> print ( stack );
    endl;

    stack -> swap ( stack );
    stack -> print ( stack );
    endl;
    // stack -> dup ( stack );
    // endl;
    // stack -> print ( stack );
    // endl;

    stack -> freeStack ( stack );

    if ( stack -> data != null )
    {
        free ( stack );
        printf ( "Stack free\n" );
    } else
        {
            printf ( "Nothing to free from the stack\n" );
        }

    return 0; 
}