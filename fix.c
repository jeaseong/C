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
    Stack* stack =(Stack*)malloc(sizeof(Stack));
    stack ->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

int isEmpty(Stack* stack)
{
    return stack->top == -1;
}

int isFull(Stack* stack)
{
    return stack->top == stack->capacity-1;
}

char peek(Stack* stack)
{
    return stack->array[stack->top];
}

void push(Stack* stack, int item)
{
    if(isFull(stack))
        return;
    stack->array[++(stack->top)] = item;
}

int pop(Stack* stack)
{
    if(isEmpty(stack))
        return -9999;
    return stack->array[(stack->top)--];
}

int isoperand(char ch)
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
    Stack* stack = createStack(strlen(exp));

    int i, k;
    
    if(!stack)
        return -1;

    for(i = 0, k = -1; exp[i]; ++i)
    {
        if(isalnum(exp[i]))
            exp[++k] = exp[i];

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
        else
        {
            while(!isEmpty(stack) && Prec(exp[i]) <= Prec(peek(stack)))
            {
                exp[++k] = pop(stack);
            }
            push(stack, exp[i]);
        }
    }

    while(!isEmpty(stack))
    {
        exp[++k] = pop(stack);
    }
    exp[++k] = '\0';
    printf("%s", exp);

    return 0;
}

int main()
{
    char exp[] = "a+b*(c^d-e)^(f+g*h)-i";
    infixToPostfix(exp);
    return 0;
}