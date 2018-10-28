//Doubly Linked list insertion operator.

#include<stdio.h>
#include<stdlib.h>

struct Node{
    int value;
    struct Node* lptr;
    struct Node* rptr;
};

void insert_front(struct Node**L,struct Node**R,int val){
    struct Node* newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->value = val;

    if(*L==NULL){
        *L=*R=newNode;
        (*L)->lptr= NULL;  // -> has more precedence than * so write it always in ().
        (*L)->rptr= NULL;
        return;
    }
    newNode->rptr = *L;
    newNode->lptr = NULL;
    (*L)->lptr = newNode;
    *L = newNode;
}

void insert_rear(struct Node**L,struct Node**R,int val){
    struct Node* newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->value = val;

    if(*L==NULL){
        *L=*R=newNode;
        (*L)->lptr= NULL;
        (*L)->rptr= NULL;
        return;
    }
    newNode->lptr = *R;
    newNode->rptr = NULL;
    (*R)->rptr = newNode;
    *R = newNode;
}

void insert_order(struct Node**L,struct Node**R,int val){
    struct Node* newNode;
    struct Node* temp = *L;
    newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->value = val;

    if(*L==NULL){
        *L=*R=newNode;
        (*L)->lptr= NULL;
        (*L)->rptr= NULL;
        return;
    }

    if(val <= (*L)->value){
        newNode->rptr = *L;
        newNode->lptr = NULL;
        (*L)->lptr = newNode;
        *L = newNode;
    }
    else if(val >= (*R)->value){
        newNode->lptr = *R;
        newNode->rptr = NULL;
        (*R)->rptr = newNode;
        *R = newNode;
    }
    else{
        while(temp->value <= val)
            temp = temp->rptr;

        newNode->lptr = temp->lptr;
        newNode->rptr = temp;
        temp->lptr->rptr = newNode;
        temp->lptr = newNode;
    }
}

void insert_specs(struct Node**L,struct Node**R,int val,int sval){
    struct Node* newNode;
    struct Node* temp = *L;
    newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->value = val;

    //here our list is not empty because user give us value which we have to put after some value,
    //so the list is not empty and we dont have to write condition for null list

    while(temp->value != sval){
        temp = temp->rptr;

        if(temp== NULL){ //this condition is special because written in while loop
            printf("your given value is not found\n");
            break;
        }
    }

    if(temp == *R)
        *R = newNode;

    newNode->lptr = temp;
    newNode->rptr = temp->rptr;
    temp->rptr->lptr = newNode; // write this always above the below sentences.
    temp->rptr = newNode;
}

void display(struct Node * H){
    struct Node *temp;
    temp = H;

    if(temp == NULL)
        printf("List is empty");

    while(temp != NULL){
        printf("%d ",temp->value);
        temp = temp->rptr;
    }
    printf("\n");

}


int main(){
    struct Node* Head;
    struct Node* Rear;
    Head = Rear = NULL;
    int val,n,sval;

    printf("1 for insert value at front:\n");
    printf("2 for insert value at rear:\n");
    printf("3 for insert value according to order:\n");
    printf("4 for insert value after specific value:\n");
    printf("5 for display the list\n");
    printf("6 for Exit\n");
    scanf("%d",&n);

    while(n !=6){

        switch(n){
        case 1:
            printf("Enter the value you want to insert:\n");
            scanf("%d",&val);
            insert_front(&Head,&Rear,val);
            break;
        case 2:
            printf("Enter the value you want to insert:\n");
            scanf("%d",&val);
            insert_rear(&Head,&Rear,val);
            break;
        case 3:
            printf("Enter the value you want to insert:\n");
            scanf("%d",&val);
            insert_order(&Head,&Rear,val);
            break;
        case 4:
            printf("Enter the value you want to insert:\n");
            scanf("%d",&val);
            printf("Enter after which value you want to insert:\n");
            scanf("%d",&sval);
            insert_specs(&Head,&Rear,val,sval);
            break;
        case 5:
            display(Head);
            break;
        default:
            printf("Enter specific value:\n");
        }

        printf("Enter which type of the operation you want to apply:\n");
        scanf("%d",&n);
    }
    return 0;
}
