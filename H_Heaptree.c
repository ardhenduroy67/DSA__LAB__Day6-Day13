#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

#define size 50
int arr[size],n=0;


void swap(int* a,int* b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}


void insert(int data)
{
	n++;
	arr[n-1]=data;
	int i=n-1;
	while(i>0)
	{
		int parent=(i-1)/2;
		if(arr[parent]<arr[i])
		{
		  swap(&arr[parent],&arr[i]);
		  i=parent;
	    }
	    else
	      return;
	}
}



void create()
{
	int val;
	int p;
	printf("Enter no. of element want to insert : ");
	scanf("%d",&p);
	for(int i=0;i<p;i++)
	{
		printf("enter the data : ");
		scanf("%d",&val);
		insert(val);
	}
}



void in_order(int i)
{
	if(i<n)
	{
		in_order(2*i +1);
		printf("%d ",arr[i]);
		in_order(2*i +2);
	}
}

void pre_order(int i)
{
	if(i<n)
	{
		printf("%d ",arr[i]);
		pre_order(2*i +1);
		pre_order(2*i +2);
	}
}

void post_order(int i)
{
	if(i<n)
	{
		post_order(2*i +1);
		post_order(2*i +2);
		printf("%d ",arr[i]);
	}
}



void heapify(int arr[],int n,int i)
{
	int largest=i;
	int l=(2*i)+1;
	int r=(2*i)+2;
	if(l<n&&arr[l]>arr[largest])
	   largest=l;
	if(r<n&&arr[r]>arr[largest])
	   largest=r;
	if(largest!=i)
	{
		swap(&arr[largest],&arr[i]);
		heapify(arr,n,largest);
	}
}



void heap_sort(int arr[],int n)
{
	for(int j=(n/2)-1; j>=0; j--)
	{
		heapify(arr,n,j);
	}
	for(int j=n-1;j>=0;j--)
	{
		swap(&arr[0],&arr[j]);
		heapify(arr,j,0);
	}
}



void display()
{
	for(int i=0; i<n; i++)
	  printf("%d ",arr[i]);
	printf("\n");
}



int main()
{
	while(1)
	{
		int ch;
		printf("enter your choice : \n");
		printf("1. Creation\n");
		printf("2. Inorder preorder postorder\n");
		printf("3. insertion\n");
		printf("4. sorting\n");
		printf("5. exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			{
				create();
				break;
			}
			case 2:
			{
				in_order(0);
				printf("\n");
				pre_order(0);
				printf("\n");
				post_order(0);
				printf("\n");
				break;
			}
			case 3:
			{
				int x;
				printf("enter the element that you want to insert : ");
				scanf("%d",&x);
				insert(x);
				break;
			}
			case 4:
			{
				heap_sort(arr,n);
			    display();
				break;
			}
			case 5:
			{
				exit(0);
				break;
			}
			default:
				break;
				
		}
	}
}