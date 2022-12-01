#include <stdio.h>
#include <stdlib.h>

typedef struct Stack{
    int top, max_size;
    char *arr;
} stk;
//7+6*5-3/9
//765+*39/-
stk *create(int _max_size){
    stk *s = (stk *)malloc(sizeof(stk));
    s->top = -1;
    s->max_size = _max_size;
    s->arr = (char *)malloc(s->max_size * sizeof(char));
}

void push(stk *s, char data){
    if (s->top == s->max_size - 1)
        printf("\nstack overflow!!\n");
    else
        s->arr[++s->top] = data;
}

char pop(stk *s){
    if (s->top == -1)
        printf("\nStack is already empty\n");
    else
        return (s->arr[s->top--]);
}

int priority(char ch)
{
    switch (ch)
    {
    case '+':
    case '-':
        return 1;

    case '*':
    case '/':
        return 3;

    case '^':
        return 5;

    default:
        return -1;
    }
}

char *infix_Postfix(char *infix)
{
    stk *s = create(50);
    char *postfix = (char *)malloc(50 * sizeof(char));
    int i, j;
    push(s, '(');
    for (i = 0, j = 0; infix[i]; i++)
    {
        char c = infix[i];
        switch (c)
        {
        case '(':
            push(s, c);
            break;

        case ')':
            while (s->arr[s->top] != '(')
                postfix[j++] = pop(s);
            pop(s);
            break;

        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
            while (priority(c) <= priority(s->arr[s->top]))
                postfix[j++] = pop(s);
            push(s, c);
            break;
        default:
            postfix[j++] = c;
        }
    }
    while (s->arr[s->top] != '(')
        postfix[j++] = pop(s);
    pop(s);
    postfix[j] = '\0';
    return postfix;
}

int main()
{
    char *infix = (char*)malloc(50*sizeof(char));
    printf("Enter the Infix Expression : \n");
    scanf("%s", infix);
    char *posfix = infix_Postfix(infix);
    printf("The postfix expression is : \n");
    printf("%s\n", posfix);
    return 0;
}