
#include<stdio.h>
#define N 20

void insert_val(int a[],int i){
    if(i==0){
        return;
    }
    int temp;

    temp = a[i];
    while( i>0 && (temp < a[(i-1)/2]) ){
        a[i] = a[(i-1)/2];
        i=(i-1)/2;
    }
    a[i] = temp;
}

void delete_min(int a[],int n){
    int temp,parent,child;
    if(n==0){
        printf("Heap is empty\n");
        return;
    }
    //item = a[0]; this is for if we want to return deleted value.
    a[0] = a[n-1];
    n--;
    temp = a[0];
    parent = 0; child = 1; //child equal to 1 because there is 2 child for parent so default LC = 1 and RC = 2;
    while(child < n){
        if(child + 1 < n && a[child + 1] < a[child] )
            child ++;
        if(temp < a[child]) break;

        a[parent] = a[child];
        parent = child;
        child = 2*parent +1;
    }
    a[parent] = temp;
}

void display(int a[],int n){
    if(n==0) printf("The Heap is empty\n");
    int i;
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\n");
}

void main(){
    int heap[N];
    int n,i=0;

    printf("Enter 1 for insert the element\n");
    printf("Enter 2 for delete the root element\n");
    printf("Enter 3 for print the heap tree\n");
    printf("Enter 4 for EXIT\n");
    scanf("%d",&n);

    while(n!=4){
        switch(n){
            case 1:
                printf("Enter the value:\n");
                scanf("%d",&heap[i]);
                insert_val(heap,i);
                i++;
                break;
            case 2:
                delete_min(heap,i);
                i--;
                break;
            case 3:
                display(heap,i);
                break;
            default:
                printf("Enter the value between 1 to 4\n");
        }
        printf("\nEnter 1/2/3/4\n");
        scanf("%d",&n);
    }
}
