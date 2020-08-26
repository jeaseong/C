#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct Stack
{
    int top;
    int capacity;
    int *array;
}Stack;

Stack* createStack(int capacity)
{
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
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
    switch (ch)
    {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        return -1;
    }

    return ch;
}

int infixToPostfix(char* exp)
{
    int i, k;

    Stack* stack = createStack(strlen(exp));
    if(!stack)
        return -1;

    for(i = 0, k = -1; exp[i]; ++i)
    {
        if(isalnum(exp[i]))
            exp[++k] = exp[i];

        else if(exp[i] =='(')
            push(stack, exp[i]);

        else if(exp[i] == ')')
        {
            while(!isEmpty(stack) && peek(stack) != '(')
                exp[++k] = pop(stack);

            if(!isEmpty(stack) && peek(stack) != '(')
                return -1;

            else
                pop(stack);
        }
        else //operator
        {
            while (!isEmpty(stack) && Prec(exp[i]) <= Prec(peek(stack)))
            {
                exp[++k] = pop(stack);
            push(stack, exp[i]);
            }
            
        }
    }
    while(!isEmpty(stack))
        exp[++k] = pop(stack);

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

// 1. 중위 표기법을 왼쪽에서 오른쪽으로 읽는다.
//     2. 문자가 피연산자 (operand) 라면 출력결과에 저장
//     3. 연산자 (operator) 라면
//         3.1. 연산자가 들어오면 자기보다 우선순위가 높거나 같은 것들을 Pop 하고 출력결과에 저장
//                (Pop 도중에 괄호가 나타나면 pop 중지), 자신을 Stack 에 Push 하시오.
//     4. 여는 괄호 (“(“) 를 만나면 무조건 Stack 에 Push 하시오.
//     5. 닫는 괄호 (“)”) 를 만나면 여는 괄호 (“(“)를 만날 때까지 Stack 에서 Pop 하여 출력결과에 저장
//     6. 2 ~ 5 번 과정을 반복
//     7. 출력결과 출력
//     8. Stack 이 Empty 가 될 때까지, Pop 하고 출력