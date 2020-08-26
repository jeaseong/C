#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Stack
{
    int top;
    unsigned capacity;
    int* array;
}Stack;

Stack* createStack(unsigned capacity)
{
    Stack* stack = (Stack*)malloc(sizeof(Stack));

    if(!stack)
        return NULL;

    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));

    return stack;
}

int isEmpty(Stack* stack)
{
    return stack->top == -1;
}

char peek(Stack* stack)
{
    return stack->array[stack->top];
}

char pop(Stack* stack)
{
    if(!isEmpty(stack))
        return stack->array[stack->top--];

    return '$';
}

void push(Stack* stack, int item)
{
    stack->array[++stack->top] = item;
}

int isOperand(char ch)
{
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

int Prec(char ch)
{
    switch(ch)
    {
        case '+':
        case '-':
            return 1;

        case '*':
        case '/':
            return 2;

        case '^':
            return 3;
    }
    return -1;
}

int infixToPostfix(char* exp)
{
    int i,k;

    Stack* stack = createStack(strlen(exp));
    if(!stack)
        return -1;

    for(i = 0, k = -1; exp[i]; ++i)
    {
        if(isOperand(exp[i]))
            exp[++k] = exp[i];

        else if(exp[i] == '(')
            push(stack, exp[i]);

        else if(exp[i] == ')')
        {
            while(!isEmpty(stack) && peek(stack) != '(')
                exp[++k] = pop(stack);
            
            if(!isEmpty(stack) && peek(stack) != '(')
                pop(stack);

            
                
        }

        else
        {
            while(!isEmpty(stack) && Prec(exp[i] <= Prec(peek(stack))))
                exp[++k] = pop(stack);

            push(stack, exp[i]);
        }

    }
    while(!isEmpty(stack))
        exp[++k] = pop(stack);

    exp[++k] = '\0';
    printf("%s", exp);
}

int main()
{
    char exp[] = "a+b*(c^d-e)^(f+g*h)-i";
    infixToPostfix(exp);
    return 0;
}