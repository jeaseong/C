#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Stack
{
    int top;
    int capacity;
    int* array;
}Stack;

Stack* createStack(int capacity)
{
    Stack* stack = (Stack*)malloc(sizeof(Stack));

    if(!stack)
        return NULL;

    stack->top = -1;
    stack->capacity = capacity;

    stack->array = (int*)malloc(sizeof(int) * stack->capacity);

    return stack;
}

int isEmpty(Stack* stack)
{
    return stack->top = -1;
}

char peek(Stack* stack)
{
    return stack->array[stack->top];
}

void push(Stack* stack, char item)
{
    stack->array[++stack->top] = item;
}

char pop(Stack* stack)
{
    if(!isEmpty(stack))
        return stack->array[++stack->top];
    return '$';
}

int Prec(char ch)
{
    switch(ch)
    {
        case '+':
            return 1;
        case '-':
            return 1;
        case '*':
            return 2;
        case '/':
            return 2;
        case '^':
            return 3;
    }
    return -1;
}

void infixToPostfix(char* exp)
{
    
    Stack* stack = createStack(strlen(exp));
    
    int k = stack->top;
    if(!stack)
        return;

    for(int i = 0, k = -1; exp[i]; ++i)
    {
        if(isalnum(exp[i]))
        {
            exp[++k] = exp[i];
        }
        else if(exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/' || exp[i] == '^')
        {
            while(!isEmpty(stack) && Prec(exp[i]) <= Prec(peek(stack)))
                exp[++k] = pop(stack);
            push(stack, exp[i]);
        }
        else if(exp[i] == '(')
        {
            push(stack, exp[i]);
        }
        else if(exp[i] == ')')
        {
            while(!isEmpty(stack) && peek(stack) != '(')
                exp[++k] = pop(stack);
            if(!isEmpty(stack) && peek(stack) == '(')
                pop(stack);
        }

    }

    while(!isEmpty(stack))
        exp[++k] = pop(stack);
    printf("%s",exp);
}

int main()
{
    char exp[] = "a+b";
    infixToPostfix(exp);
    return 0;
}
