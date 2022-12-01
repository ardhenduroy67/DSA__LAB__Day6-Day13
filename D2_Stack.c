#include<stdio.h>
#include<stdlib.h>
#define size 50

int top=-1;
int s[size];
 
// Push Function
void push(){
	int x;
	if(top==(size-1)){
		printf("\nOverflow!!\n");
	}
	else{
		printf("\nElement to Push : ");
		scanf("%d",&x);
		top=top+1;
		s[top]=x;
	}
}
 
// Pop Function
void pop(){
	if(top==-1){
		printf("\nUnderflow!!\n");
        return;
	}
	else{
		printf("\nPopped element:  %d",s[top]);
		top=top-1;
	}
}

// Display Function
void Display(){
	if(top==-1){
		printf("\nUnderflow!!");
	}
	else{
		printf("\nElements in stack : ");
		for(int i=top;i>=0;--i){
			printf("%d  ",s[i]);
        }
	}
    printf("\n");
}

int main()
{
	int ch;
	while(1){
		printf("\n1.Push  2.Pop  3.Display  4.Exit : ");
		scanf("%d",&ch);		
		switch(ch)
		{
        case 1: 
            push();
            break;
        case 2: 
            pop();
            break;
        case 3: 
            Display();
            break;
        case 4: 
            exit(0);
		}
	}
}
