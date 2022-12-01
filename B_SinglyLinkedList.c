#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data; struct node *next;
} nd;

// Creation Of Singly LinkedList
nd* Create_LinkedList(){
    nd* head=NULL;
    int n;
    printf("Element : ");
    nd* ptr=(nd*)malloc(sizeof(nd));
    scanf("%d",&ptr->data);
    head=ptr;
    printf("To continue Insert 1 : ");
    scanf("%d",&n);
    while(n==1){
        nd* temp=(nd*)malloc(sizeof(nd));
        printf("Element : ");
        scanf("%d",&temp->data);
        ptr->next=temp;
        ptr=ptr->next;
        printf("To continue Insert 1 : ");
        scanf("%d",&n);
    }
    ptr->next=NULL;
    return head;
}

// 2. Display 
void display(nd* head){
    printf("\n");
    nd* ptr=head;
    printf("Display : ");
    while(ptr){
        printf("%d  ", ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
}

// 3. Display using recursive function 
void display_recursion(nd* head){
    if(head){
        printf("%d  ",head->data);
        display_recursion(head->next);
    }
}

// Search an Element
int search(nd* head,int x){
    nd* ptr=head;
    int index=1;
    while(ptr){
        if(ptr->data==x){
            return index;
        }
        ptr=ptr->next;
        index++;
    }
    return -1;
}

// Insertion Operation
void insert(nd** head, int data, int pos)
{
    if(pos<1)
        printf("Invalid position!!\n");
    else if(pos==1){
        nd *ptr=(nd*)malloc(sizeof(nd));
        ptr->data=data;
        ptr->next=*head;
        *head=ptr;
    }
    else if(*head==NULL)
        printf("Invalid Position!!\n");
    else{
        nd *temp=*head,*ptr=(nd*)malloc(sizeof(nd));
        int i=2;
        while(i<pos && temp){
            temp=temp->next;
            i++;
        }
        if(temp){
            ptr->data=data;
            ptr->next=temp->next;
            temp->next=ptr;
        }
        else{
            printf("Invalid Position!!\n");
        }
    }
}

// Deletion of an Element
void delete(nd** head, int pos)
{
    if(pos<1 || *head==NULL)
        printf("Invalid Position!!\n");
    else if(pos==1){
        nd *temp=*head;
        *head=(*head)->next;
        free(temp);
    }
    else{
        nd *temp=*head;
        for(int i=2;i<pos && temp->next;i++)
            temp=temp->next;
        if(temp->next){
            nd *ptr=temp->next;
            temp->next=temp->next->next;
            free(ptr);
        }
        else{
            printf("Invalid Position!!\n");
        }
    }
}

// Reverse print
void display_reverse(nd *head){
    if(head){
        display_reverse(head->next);
        printf("%d  ",head->data);
    }
}

// reverse LinkedList
nd *reverse(nd *head){
    nd *prev=NULL, *curr=head, *nextlist=head;
    while(nextlist)    {
        nextlist=nextlist->next;
        curr->next=prev;
        prev=curr;
        curr=nextlist;
    }
    return prev;
}

int main(){
    nd *head=NULL;
    while(1)
    {
        printf("\n1) Create LinkedList :\n2) Display LinkedList :\n3) Recursive Display :\n4) Search an Element :\n5) Insert an Element :\n6) Delete an Element :\n7) Reverse Print :\n8) Reverse the LinkedList :\n9) Exit :\n");
        int choice;
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            head=Create_LinkedList();
            break;
        case 2:
            display(head);
            break;
        case 3:
            printf("\nRecursive Display : ");
            display_recursion(head);
            printf("\n");
            break;
        case 4:
            int x, pos;
            printf("Element to be searched : ");
            scanf("%d",&x);
            if(search(head,x)==-1)
                printf("Not Present\n");
            else
                printf("Present at Index : %d\n",search(head,x));
            break;
        case 5:
            printf("Position to be inserted : ");
            scanf("%d",&pos);
            printf("Enter the data : ");
            scanf("%d", &x);
            insert(&head, x, pos);
            break;
        case 6:
            printf("Position to be Deleted : ");
            scanf("%d",&pos);
            delete(&head, pos);
            break;
        case 7:
        printf("\n");
            printf("Reverse Display : ");
            display_reverse(head);
            printf("\n");
            break;
        case 8:
            head=reverse(head);
            break;
        case 9:
            exit(0);
            break;
        }
    }
    return 0;
}