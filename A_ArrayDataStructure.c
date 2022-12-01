#include<stdio.h>
#include<stdlib.h>

int arr[100];

// Array Creation
int create_Array(){
    printf("Enter Size of Array : ");
    int n; scanf("%d",&n);
    printf("Enter Array Elements : ");
    for(int i=0;i<n;i++){
        int x;
        scanf("%d", &x);
        arr[i]=x;
    }
    return n;
}

// Display of Array Elements 
void display(int n){
    printf("\nElememts : ");
    for(int i=0;i<n;i++){
        printf("%d  ",arr[i]);
    }
    printf("\n\n");
}

// Selection Sort
void Selection_Sort(int n){
    int j,min;
    for(int i=0;i<n-1;i++){
        min=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[min]){
                min=j;
            }
        }
        if(min!=i){
            int temp=arr[min];
            arr[min]=arr[i];
            arr[i]=temp;
        }
    }
}

// Bubble Sort
void Bubble_Sort(int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}

// Modified Bubble Sort
void Bubble_Sort_Modified(int n){
    int flag;
    for(int i=0;i<n-1;i++){
        flag=0;
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                flag=1;
            }
        }
        if(!flag){
            break;
        }
    }
}

// Insertion Sort
void Insertion_Sort(int n){
    int j,key;
    for(int i=1;i<n;i++){
        key=arr[i];
        for(j=i-1;j>=0 && arr[j]>key;j--){
            arr[j+1]=arr[j];
        }
        arr[j+1]=key;
    }
}

// Merge Sort
void merge(int l,int m,int r){
    int i,j,k;
    int n1=m-l+1;
    int n2=r-m;
    int L[n1], R[n2];
    for(i=0;i<n1;i++){
        L[i]=arr[l+i];
    }
    for(j=0;j<n2;j++){
        R[j]=arr[m+1+j];
    }
    i=0; j=0; k=l;
    while(i<n1 && j<n2){
        if(L[i]<=R[j]){
            arr[k]=L[i];
            i++;
        }
        else{
            arr[k]=R[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        arr[k]=L[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k]=R[j];
        j++;
        k++;
    }
}
void Merge_Sort(int l, int r)
{
    if(l<r){
        int m=l+(r-l)/2;
        Merge_Sort(l,m);
        Merge_Sort(m+1,r);
        merge(l,m,r);
    }
}

int main() {
    while(1){
        printf("1) Create Array Data Structure :\n2) Display of Array Elements :\n3) Selection Sort :\n4) Bubble Sort :\n5) Modified Bubble Sort :\n6) Insertion Sort :\n7) Merge Sort :\n8) Exit :\n");
        int n;
        scanf("%d",&n);
        int length,len;
        switch(n)
        {
        case 1:
            length=create_Array(arr);
            len=length;
            break;
        case 2:
            display(len);
            break;
        case 3:
            Selection_Sort(len);
            break;
        case 4:
            Bubble_Sort(len);
            break;
        case 5:
            Bubble_Sort_Modified(len);
            break;
        case 6:
            Insertion_Sort(len);
            break;
        case 7:
            Merge_Sort(0,len-1);
            break;
        case 8:
            exit(0);
        }
    }
    return 0;
}