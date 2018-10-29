#include<stdio.h>
#include<stdlib.h>

struct node{
    int value;
    int priority;
    struct node* ptr;
};

struct node* enqueue(struct node* head,int pri,int val){
    struct node* newNode,*temp;
    temp = head;
    newNode = (struct node*) malloc(sizeof(struct node));
    if(newNode == NULL){
        printf("Malloc Failed\n");
        return head;
    }

    newNode->value = val;
    newNode->priority= pri;

    if(head == NULL || (newNode->priority < head->priority)){
        newNode->ptr = head;
        head = newNode;
    }
    else{
        while( (temp->ptr != NULL) && (newNode->priority) >= (temp->ptr->priority) )
            temp = temp->ptr;

        newNode->ptr = temp->ptr;
        temp->ptr= newNode;
    }

    return head;
}

struct node* dequeue(struct node* head){
    struct node *temp;
    if(head == NULL){
        printf("List is empty\n");
    }
    else{
        temp = head;
        head = head->ptr;
        printf("%d with priority %d is processed",temp->value,temp->priority);
        free(temp);
    }
    return head;
}

void display(struct node* head){
    if(head == NULL){
        printf("List is empty\n");
    }
    else{
        while(head!= NULL){
            printf("%d ",head->value);
            head =head->ptr;
        }
    }
}

void main(){
    int n,val,p;
    struct node* head;
    head = NULL;

    printf("Enter 1 for enqueue\n");
    printf("Enter 2 for dequeue\n");
    printf("Enter 3 for display\n");
    printf("Enter 4 for EXIT\n");
    scanf("%d",&n);

    while(n!=4){
    switch(n){
    case 1:
        printf("Enter priority and value respectively\n");
        scanf("%d %d",&p,&val);
        head = enqueue(head,p,val);
        break;
    case 2:
        head = dequeue(head);
        break;
    case 3:
        display(head);
        break;
    default:
        printf("Enter value between 1 to 4\n");
    }
    printf("Enter 1/2/3/4 :\n");
    scanf("%d",&n);
    }
}
