#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

typedef struct node
{
	int data;
	struct node* left;
	struct node* right;
}TreeNode;

TreeNode* root = NULL;


void inorder(TreeNode* root)
{
    if(root==NULL)
	return;
	inorder(root->left);
	printf("%d ",root->data);
	inorder(root->right);	
}


void preorder(TreeNode* root)
{
    if(root==NULL)
	return;
	printf("%d ",root->data);
	preorder(root->left);
	preorder(root->right);	
}


void postorder(TreeNode* root)
{
    if(root==NULL)
	return;
	postorder(root->left);
	postorder(root->right);
	printf("%d ",root->data);
}


TreeNode* newNode(int item)
{
    TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
    temp->data = item;
    temp->left =NULL;
	temp->right = NULL;
    return temp;
}



TreeNode* insert(TreeNode* node, int key)
{
    if (node == NULL)
        return newNode(key);
    if (key < node->data)
        node->left = insert(node->left, key);
    else if (key > node->data)
        node->right = insert(node->right, key);
    return node;
}



void creation(){
    int i,n;
    printf("enter the number of elements : ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("enter the element : ");
        int val;
        scanf("%d",&val);
        if(root==NULL){
            TreeNode* temp=(TreeNode*)malloc(sizeof(TreeNode));
            temp->data=val;
            temp->left=NULL;
            temp->right=NULL;
            root=temp;
        }
        else{
            TreeNode* ptr=root;
            insert(ptr,val);
		}
	}
}



TreeNode* minValue(TreeNode* root)
{
    TreeNode* current = root;
    while (current && current->left != NULL)
        current = current->left;
  
    return current;
}

TreeNode* deletion(TreeNode* root,int val)
{
	TreeNode* temp;
	if(root==NULL)
	  printf("no element present\n");
	else if(root->data>val)
	    root->left=deletion(root->left,val);
	else if(root->data<val)
	    root->right=deletion(root->right,val);
    else{ //element found
    	if(root->left && root->right)
    	{
    		temp=minValue(root->right);
    		root->data=temp->data;
    		root->right=deletion(root->right,root->data);
		}
		else{ 
			temp=root;
			if(root->left==NULL)
			   root=root->right;
			if(root->right==NULL)
			   root=root->left;
			free(temp);
		}
	}
	return root;
}

TreeNode* search(TreeNode* root,int x)
{
	if(root==NULL)
	return NULL;
    if(root->data<x)
	  return search(root->right,x);
	else if(root->data>x)
	   return search(root->left,x);
	
	return root; 
}


int main()
{
	while(1)
	{
		int ch;
		printf("enter your choice\n");
		printf("1. Creation\n");
		printf("2. Inorder preorder postorder\n");
		printf("3. insertion\n");
		printf("4. searching\n");
		printf("5. deletion\n");
		printf("6. exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			{
				creation();
				break;
			}
			case 2:
			{
				inorder(root);
				printf("\n");
				preorder(root);
				printf("\n");
				postorder(root);
				printf("\n");
				break;
			}
			case 3:
			{
				int x;
				printf("enter the element that you want to insert ");
				scanf("%d",&x);
				insert(root,x);
				break;
			}
			case 4:
			{
				int x;
				printf("enter the element that you want to search ");
				scanf("%d",&x);
				TreeNode* temp=search(root,x);
				if(temp==NULL)
				  printf("element is not present\n");
				else
				  printf("element is present\n");
				break;
			}
			case 5:
			{
				int x;
				printf("enter the element that you want to delete ");
				scanf("%d",&x);
				deletion(root,x);
				break;
			}
			case 6:
			{
				exit(0);
				break;
			}
			default:
				break;
				
		}
	}
}