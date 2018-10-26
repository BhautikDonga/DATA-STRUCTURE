//queue using two stacks

#include<stdio.h>
#define N 4

int top1= -1,top2=-1;
int s1[N]={},s2[N]={};


void push(int val,int n){
    if(n==1){
        if(top1 != N-1){
            s1[++top1]=val;
        }
        else{
            printf("Queue is full so %d is not inserted\n",val);
        }
    }
    else{
        s2[++top2]= val;
    }
}

int pop(int n){
    int temp;
    if(n==1){
        temp  = s1[top1--];
    }
    else{
        temp = s2[top2--];
    }
    return temp;
}


void insertValue(int value){
    push(value,1);
}

int deleteValue(){
    int temp;
    if(top1 == -1 && top2 == -1)
        printf("Queue is empty\n");
    else{
        if(top2 != -1)
            pop(2);
        else{
            while(top1 != -1){
                temp= pop(1);
                push(temp,2);
            }
            pop(2);
        }
    }
}

void display(){
    int i;
    for(i=top2;i>-1;i--){
        printf("%d ",s2[i]);
    }
    for(i=0;i<=top1;i++){
        printf("%d ",s1[i]);
    }
    printf("\n");
}

void main(){
    int n,value,temp;
    printf("Enter 1 for Enqueue\n");
    printf("Enter 2 for Dequeue\n");
    printf("Enter 3 for Display\n");
    printf("Enter 4 for Exit\n");
    scanf("%d",&n);

    while(n!=4){
    switch(n){
    case 1:
        printf("Enter the value you want to be inserted\n");
        scanf("%d",&value);
        insertValue(value);
        break;
    case 2:
        temp = deleteValue();
        printf("%d is deleted\n",temp);
        break;
    case 3:
        display();
        break;
    default:
        printf("Enter correct number\n");

    }
    printf("Enter which type of operation you prefer:\n");
    scanf("%d",&n);
    }
}
