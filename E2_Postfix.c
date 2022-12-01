#include<stdio.h>
# include<stdlib.h>
# include<math.h>
# include<ctype.h>
#define size 1000

typedef struct stack{
    int top;
    int s[size];
}stk;
// 765*+39/-

void push(int x,stk *stk1){
    if(stk1->top==size-1){
        printf("\nOverflow");
    }
    else{
        stk1->top+=1;
        stk1->s[stk1->top] = x;
    }
}

int pop(stk *stk1){
    if(stk1->top==-1){
        return -1;
    }
    else{
        int x = stk1->s[stk1->top];
        stk1->top-=1;
        return x;
    }
}

int main(){
	int i,ch;
	stk * stk1=(stk*)malloc(sizeof(stk));
	stk1->top=-1;
	printf("Enter the expression : ");
	char exp[1000];
	scanf("%s",exp);
	int x,y,r;
	for(i=0;i<sizeof(exp)/sizeof(exp[0]);i++)
	{
		 ch=exp[i];
		switch(ch)
		{
			case '+':
				y=pop(stk1);
				x=pop(stk1);
				push(x+y,stk1);
				break;
			
			case '-':
				y=pop(stk1);
				x=pop(stk1);
				push(x-y,stk1);
				break;
				
			case '*':
				y=pop(stk1);
				x=pop(stk1);
				push(x*y,stk1);
				break;
				
			case '/':
				y=pop(stk1);
				x=pop(stk1);
				push(x/y,stk1);
				break;
				
			case '^':
				y=pop(stk1);
				x=pop(stk1);
				//int p=pow(x^y);
				push(pow(x,y),stk1);
				break;
				
			default :
				r=exp[i]-'0';
				push(r,stk1);
				break;					
		}
	}
	printf("%d",stk1->s[0]);
    return 0;
}