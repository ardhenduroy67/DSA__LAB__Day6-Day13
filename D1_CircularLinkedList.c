#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node * link;
}nd;

void viewlist(nd* start){
    nd* ptr=start;
    if(ptr){
        printf("\nCircular LinkedList :  ");
        do{
            printf("%d  ",ptr->data);
            ptr=ptr->link;
        }while(ptr!=start);
        printf("\n");
    }
    else{
        printf("\nNo element present\n");
    }
}

int length(nd* start){
    nd* ptr=start;
    int count=0;
    if(start==NULL){
        return count;
    }
    else{
        do{
            count++;
            ptr=ptr->link;
        }while(ptr!=start);
        return count;
    }
}
int search_val(int val,nd * start){
   nd * temp=start;
    if(start->data==val){
        return 2;
    }
    do{
        if(temp->data==val){
            return 1;
        }
        temp=temp->link;
    }while(temp!=start);
    return 0;
}
nd* insertion(nd* start){
    int pos,len=length(start);
    printf("\nPosition to be Inserted : ");
    scanf("%d",&pos);
    if(pos<1 || pos>len+1){
        printf("\nInvalid position !\n");
    }
    else if(pos==1){
        nd * p=start;
        while(p->link!=start){
            p=p->link;
        }nd * newnode=(nd *)malloc(sizeof(nd));
        printf("Enter data\n");
        scanf("%d",&newnode->data);
        newnode->link=start;
        start=newnode;
        p->link=start;
        return start;
    }
    else if(pos==len+1){
        nd * p=start;
        while(p->link!=start){
            p=p->link;
        }
        nd * newnode=(nd*)malloc(sizeof(nd));
        newnode->link=NULL;
        printf("Enter data\n");
        scanf("%d",&newnode->data);
        p->link=newnode;
        newnode->link=start;
        return start;
    }
    else{
        nd * newnode=(nd *)malloc(sizeof(nd));
        printf("Enter data\n");
        scanf("%d",&newnode->data);
        newnode->link=0;
        int i=1;
        nd * p=start;
        while(i!=pos-1){
            i++;
            p=p->link;
        }
        newnode->link=p->link;
        p->link=newnode;
          return start;
    }
}
nd* deletion(nd* start){
    struct node * p=start;
    if(start){
        int pos,len=length(start);
        printf("\nPosition to be Deleted : ");
        scanf("%d",&pos);
        if(pos<1 || pos>len){
            printf("\nInvalid position !\n");
        }
        else if(pos==1){
            nd* p=start;
            if(start){
                if(start->link==start){
                    start=NULL;
                    free(p);
                }
                else{
                    while(p->link!=start){
                        p=p->link;
                    }
                    struct node * q=start;
                    start=q->link;
                    p->link=q->link;
                    free(q);
                }
            }
            return start;
        }
        else if(pos==len){
            if(start){    
                if(start->link==start){
                    start=NULL;
                    free(p);
                    return start;
                }
                while(p->link->link!=start){
                    p=p->link;
                }
                nd* q=p->link;
                p->link=start;
                free(q);
            }
            return start;
        }
        else{
            int i=1;
            while(i!=pos-1){
                i++;
                p=p->link;
            }
            nd* q=p->link;
            p->link=q->link;
            free(q);
        }
    }
    return start;
}
nd * create(struct node * start){
    nd* newnode,*temp;
    start=NULL;
    int choice=1;
    while(choice==1){
        newnode=(nd*)malloc(sizeof(struct node));
        printf("Enter data : ");
        scanf("%d",&newnode->data);
        newnode->link=NULL;
        if(start==NULL){
            start=newnode;
            temp=newnode;
            temp->link=start;
        }
        else{
            temp->link=newnode;
            temp=newnode;
            temp->link=start;
        }
        printf("To continue Insert 1 : ");
        fflush(stdin);
        scanf("%d",&choice);
    }
    return start;
}
void searching(nd* start){
    if(start){
        printf("Element to be Searched : ");
        int val;
        scanf("%d",&val);
        nd* ptr=start;
        int pos=0;
        do{
            pos++;
            if(ptr->data==val){
                printf("\nElement is at Pos : %d\n",pos);
                return;
            }
            ptr=ptr->link;
        }while(ptr!=start);
        printf("\nElement Not Present\n");
    }
    else{
        printf("\nLinkedList NULL\n");
    }
}
// nd* reverse(nd * start){
//     if(start){
//         nd* prevnode,* currnode,*nextnode;
//         prevnode=NULL;
//         currnode=start;
//         do{
//             nextnode=currnode->link;
//             currnode->link=prevnode;
//             prevnode=currnode;
//             currnode=nextnode;
//         }while(currnode!=start);
//         currnode->link=prevnode;
//         start=prevnode;
//     }
//     return start;
// }

int main() {
    nd* start=NULL;
    while(1){
        int choice;
        printf("\n1)Creation 2)Display 3)Insertion 4)Search 5)Deletion 6)Exit : ");
        scanf("%d",&choice);
        printf("\n");
        switch(choice){
            case 1:
                start=create(start);
                break;
            case 2:
                viewlist(start);
                break;
            case 3:
                start= insertion(start);
                break;
            case 4:
                searching(start);
                break;
            case 5:
                start=deletion(start);
                break;
            case 6:
                exit(0);
        }
    }
    return 0;
}