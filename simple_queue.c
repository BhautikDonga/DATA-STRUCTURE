#include<stdio.h>
#define N 5
int front = -1,rear= -1;

void enqueue(int q[],int val){
    if(rear == N-1){
        printf("queue is full so %d is not inserted\n",val);
    }
    else{
        q[++rear] = val;
        if(front == -1)
            front=0;
    }
}

void dequeue(int q[]){
    if(front == -1){
        printf("Queue is empty\n");
    }
    else if(front == rear){
        printf("%d is removed\n",q[front]);
        front = rear = -1;
    }
    else{
        printf("%d is removed\n",q[front]);
        front++;
    }
}

void display(int q[]){
    int i=front;

    if(i==-1){
        printf("The queue is empty\n");
    }
    else{
        for(i;i<=rear;i++)
            printf("%d ",q[i]);
    }
}

int main(){
    int q[N],val,n;
    printf("Enter 1 for enqueue:\n");
    printf("Enter 2 for dequeue:\n");
    printf("Enter 3 for display:\n");
    printf("Enter 4 for EXIT\n");
    scanf("%d",&n);

    while(n!=4){
        switch(n){
            case 1:
                printf("Enter the value you want to be inserted\n");
                scanf("%d",&val);
                enqueue(q,val);
                break;
            case 2:
                dequeue(q);
                break;
            case 3:
                display(q);
                break;
            default:
                printf("Enter value between 1 to 3\n");
        }
        printf("Enter 1/2/3 as given above\n");
        scanf("%d",&n);
    }
    return 0;
}
