#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct queue{
	int data;
	struct queue* link;
}q;

q* rear=NULL;
q* front=NULL;

void insert()
{
	int x;
	q* newnode=(q*)malloc(sizeof(q));
	printf("enter the data you want to insert : ");
	scanf("%d",&newnode->data);
	newnode->link=NULL;
	if(front==NULL){
		front=newnode;
		rear=newnode;
	}
	else{
		rear->link=newnode;
		rear=newnode;
	}
	//return front;
}

void Delete()
{
	if(front==NULL)
	  printf("no element present in the queue.\n");
	else{
		if(front==rear)
		  rear=NULL;
		q* temp=front;
		front=front->link;
		free(temp);
	}
	//return front;
}

void display()
{
	if(front==NULL)
	  printf("The queue is empty.\n");
	else{
	printf("front->");
	q* ptr=front;
	while(ptr)
	{
		printf("%d ",ptr->data);
		ptr=ptr->link;
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
			
			default: printf("\nInvalid choice!!");
		}
	}
}