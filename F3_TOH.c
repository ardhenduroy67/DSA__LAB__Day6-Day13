#include<stdio.h>
void t_o_h(int n,char a,char b,char c)
{
    if(n==1){
    printf("\nMove from %c to %c",a,c);
    return;
    }
    else if(n>1)
    {
        t_o_h(n-1,a,c,b);
        printf("\nMove from %c to %c",a,c);
        t_o_h(n-1,b,a,c);
    }
}
int main(){
    int n;
    printf("Please enter the number : ");
    scanf("%d",&n);
    char a='A',b='B',c='C';
    t_o_h(n,a,b,c);
    return 0;
}