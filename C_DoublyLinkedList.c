
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* prev,*next;
}nd;

// Creation
nd* create(nd* head){
    nd* temp;
    int ch;
    do{
        nd* newnode=(nd*)malloc(sizeof(nd));
        printf("Enter Data : ");
        scanf("%d",&newnode->data);
        newnode->prev=NULL;
        newnode->next=NULL;
        if(head==NULL){
            head=newnode;
            temp=newnode;
        }
        else{
            temp->next=newnode;
            newnode->prev=temp;
            temp=newnode;
        }
        printf("To Continue Insert 1 : ");
        fflush(stdin);
        scanf("%d",&ch);
    }while(ch==1);
    return head;
}

// Display
void display(nd* head){
    if(head){
        nd* temp=head;
        printf("\nDoubly LinkedList :  ");
        while(temp!=NULL){
            printf("%d  ",temp->data);
            temp=temp->next;
        }
        printf("\n");
    }
    else{
        printf("NULL\n");
    }
}

// Recursive Display
void Recursive_Display(nd* head){
    if(head==NULL){
        return;
    }
    printf("%d  ",head->data);
    Recursive_Display(head->next);
}

// Length
int length(nd* head){
    if(head){
        nd* temp=head;   
        int count=0;
        while(temp){
            count++;
            temp=temp->next;
        }
        return count;
    }
    return 0;
}

// Reverse Print
void reverse_print(nd* head){
    if(head==NULL){
        return;
    }
    reverse_print(head->next);
    printf("%d  ",head->data);
}

// Search
void searching(nd* head){
    if(head){
        printf("\nElement to be searched : ");
        int key,i=1;
        scanf("%d",&key);
        nd* temp=head;
        while(temp){
            if(temp->data==key){
                printf("\nPresent at Index : %d\n",i);
                return;
            }
            else{
                i++;
                temp=temp->next;
            }
        }
        printf("\nNot Present\n");
        // break;
    }
    else{
        printf("\nLinkedList NULL\n");
    }
}

// Insertion
nd* insertion(nd* head){
    if(head){
        int pos,len=length(head);
        printf("\nPosition to be Inserted : ");
        scanf("%d",&pos);
        if((pos>len+1) || pos<1){
            printf("\nInvalid Positon\n");
        }
        else if(pos==1){
            nd* newnode=(nd*)malloc(sizeof(nd));
            printf("\nEnter data : ");
            scanf("%d",&newnode->data);
            newnode->prev=NULL;
            newnode->next=NULL;
            newnode->next=head;
            head->prev=newnode;
            head=newnode;
        }
        else if(pos==len+1){
            nd* newnode=(nd*)malloc(sizeof(nd));
            printf("\nEnter data : ");
            scanf("%d",&newnode->data);
            newnode->prev=NULL;
            newnode->next=NULL;
            nd* temp=head;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=newnode;
            newnode->prev=temp;
        }
        else{
            nd* newnode=(nd*)malloc(sizeof(nd));
            printf("\nEnter data : ");
            scanf("%d",&newnode->data);
            newnode->prev=NULL;
            newnode->next=NULL;
            nd* temp=head;
            int i=1;
            while(i!=pos-1){
                i++;
                temp=temp->next;
            }
            newnode->next=temp->next;
            newnode->prev=temp;
            temp->next->prev=newnode;
            temp->next=newnode;
        }
        return head;
    }
    else{
        nd* newnode=(nd*)malloc(sizeof(nd));
        printf("\nEnter data : ");
        scanf("%d",&newnode->data);
        newnode->prev=NULL;
        newnode->next=NULL;
        head=newnode;
        return head;
    }
}

// Deletion
nd* deletion(nd* head){
    if(head){
        printf("\nPosition to be Deleted : ");
        int pos,len=length(head);
        scanf("%d",&pos);
        if(pos<1 || pos>len){
            printf("\nInvalid Position\n");
        }
        else{
            nd* temp=head; 
            if(pos==1){
                if(head->next==NULL){
                    head=NULL;
                    free(temp);
                }
                else{
                    head=head->next;
                    head->prev=NULL;
                    free(temp);
                }
            }
            else if(pos==len){
                while(temp->next!=NULL){
                    temp=temp->next;
                }
                nd* pt=temp->prev;
                pt->next=NULL;
                free(temp);
            }
            else{
                int i=1;
                while(i!=pos-1){
                    temp=temp->next;
                    i++;
                }
                nd* pt=temp->next;
                temp->next=pt->next;
                pt->next->prev=temp;
                free(pt);
            }
        }
        return head;
    }
    else{
        printf("\nLinkedList is NULL\n");
    }
}

// Reverse
nd* reverse(nd* head){
    if(head){
        nd* tail=head;
        while(tail->next!=NULL){
            tail=tail->next;
        }
        nd* currnode=head,*nextnode;
        while(currnode){
            nextnode=currnode->next;
            currnode->next=currnode->prev;
            currnode->prev=nextnode;
            currnode=nextnode;
        }
        head->next=currnode;
        head=tail;
        currnode=head;
        return head;
    }
    else{
        printf("linked list is empty\n");
    }
}

int main(){
    nd* head=NULL;
    int ch;
    do{
        printf("\n1) Creation :\n2) Display :\n3) Recursion Display :\n4) Searching : \n5) Insertion : \n6) Deletion : \n");
        printf("7) Reverse print :\n8) Reverse LinkedList :\n9) Exit :\n\n");
        scanf("%d",&ch);
        switch(ch){
        case 1:
            head=create(head);
            break;
        case 2:
            display(head);
            break;
        case 3:
            if(head){
                printf("\nRecursive Display : ");
                Recursive_Display(head);
                printf("\n");
            }
            else{
                printf("LinkedList NULL\n");
            }
            break;
        case 4:
            searching(head);
            break;
        case 5:
            head=insertion(head);
            break;
        case 6:
            head=deletion(head);
            break;
        case 7:
            if(head){
                printf("\nReversed Print : ");
                reverse_print(head);
                printf("\n");
            }
            else{
                printf("LinkedList NULL\n");
            }
            break;
        case 8:
            head=reverse(head);
            break;
        case 9:
            exit(0);
            break;
        }
    }while(ch!=0);
    return 0;
}