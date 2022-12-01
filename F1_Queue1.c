#include<stdio.h>
#include<stdlib.h>

#define MAX 10

int q[MAX];
int front=0;
int rear=-1;

void insert()
{
	int x;
	if(rear==MAX-1)
	  printf("insertion is not possible.\n");
	else
	{
		printf("enter the element want to insert : ");
		scanf("%d",&x);
		rear=rear+1;
		q[rear]=x;
	}
}

int Delete()
{
	if(front>rear)
	  printf("underflow.");
	else
	{
		int x=q[front];
		front=front+1;
		return(x);
	}
}

void display()
{
	if(front>rear)
	  printf("The queue is empty\n");
	else{
	printf("front->");
	for(int i=front;i<=rear;i++)
	{
		printf("%d ",q[i]);
	}
	printf("<-rear");
}
}

int main()
{
	int ch;
	while(1)	
	{
		printf("\nOperations performed in queue : ");
		printf("\n1.insert the element\n2.delete the element\n3.Display\n4.exit");
		printf("\n\nEnter the choice : ");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1: insert();
					break;
			case 2: Delete();
					break;
			case 3: display();
					break;
			case 4: exit(0);
			
			default: printf("\nInvalid choice");
		}
	}
	
}