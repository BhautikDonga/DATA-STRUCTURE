#include<stdio.h>

void push(int[],int,int);
int pop(int[],int);

int top= -1;

int main(){
    int value,n,i,a[5];
    printf("Enter 1 for push: \n");
    printf("Enter 2 for pop: \n");
    printf("Enter 3 for display: \n");
    printf("Enter 4 for exit: \n");
    scanf("%d",&n);

    while(n!=4){
    switch(n){
    case 1:
        printf("Enter value to push: ");
        scanf("%d",&value);
        push(a,5,value);
        break;
    case 2:
        printf("%d is remove \n",pop(a,5));
        break;
    case 3:
        printf("the stack is .. ");
        for(i=0;i<=top;i++){
            printf("%d ",a[i]);
        }
        break;
    default:
        printf("Enter valid number: \n");
    }

    printf("Enter 1/2/3/4: \n");
    scanf("%d",&n);
    }

    return 0;

}

void push(int a[],int size,int value){
    if(top <  size-1)
        a[++top] = value;
    else
        printf("Sorry Value didn't push BCOZ stack is full\n");
}

int pop(int a[],int size){
    if(top>=0)
        return a[top--];
    else
        printf("your stack is empty \n");
}


