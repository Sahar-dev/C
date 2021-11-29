#include <stdio.h>
#include <stdlib.h>
//functions

//funding the index of x in the array
int indexOf(int *T,int n,int x){
    if(n<0)
        return n;
    if(*(T+n)==x)
        return n;
    return indexOf(T,n-1,x);
}

//deleteing the element
void removing(int *T,int *n, int x){
    int a = indexOf(T,*n-1,x);
    if(a>=0){
        for (int i = a; i < *n-1; i++)
        {
            *(T+i)=*(T+i+1);
        }
    *n=*n-1;
    removing(T,n,x);
    }
}


void main(){
    int *T,n,x;
    do
    {
        printf(" Table length : ");
        scanf("%d",&n);
    } while ( n<=0);
    T=malloc(n*4);
    for (int i = 0; i < n; i++){
        printf("The Element number %d : ",i+1);
        scanf("%d",T+i);
    }
    printf("which element you would like to delete : ");
    scanf("%d",&x);
    removing(T,&n,x);
    T=realloc(T,n*4);
    for (int i = 0; i < n; i++)
    {
        printf("%d \t",*(T+i));
    }

    system("pause");
}
