#include<stdio.h>
#define N 3

int F=-1,R=-1;

void enqueue(int q[],int val){
    if((R+1)%N==F){
        printf("Queue is full %d is not inserted\n",val);
        return;
    }
    R=(R+1)%N;
    q[R]=val;

    if(F==-1)
        F=0;
}

int dequeue(int q[]){
    int item;

    if(F==-1){
        printf("Queue is empty\n");
        return 0;
    }
    item=q[F];
    if(F==R)
        F=R=-1;
    else
        F=(F+1)%N;

    return item;
}

void display(int q[]){
    int i;
    i=F;

    do{
        printf("%d\t",q[i]);
        i=(i+1)%N;
    }while(i!=F);
    printf("\n");

}

int main(){
    int q[N];
    int val,n,item;

    printf("Enter 1 for insert\n");
    printf("Enter 2 for delete\n");
    printf("Enter 3 for display\n");
    printf("Enter 4 for exit\n");

    scanf("%d",&n);

    while(n!=4){
    switch(n){
    case 1:
        printf("Enter the value to enter\n");
        scanf("%d",&val);
        enqueue(q,val);
        break;
    case 2:
        item = dequeue(q);
        if(item !=0) printf("%d is deleted\n",item);
        break;
    case 3:
        display(q);
        break;
    case 4:
         break;   
            
    default:
        printf("Enter perfect value\n");

    }
    printf("Enter number according to operation\n");
    scanf("%d",&n);

    }
}

