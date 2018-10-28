//inserted values and new node inserted at front .
// simple linked list
#include<stdio.h>
#include<stdlib.h>

struct Node{
    struct Node *ptr;
    int value;
};

struct Node* insertValue(struct Node*H,int val,int n){
    struct Node* newNode;
    struct Node* temp=H;

    newNode = (struct Node*)malloc(sizeof(struct Node));

    if(newNode==NULL){
        printf("malloc failed\n");
        return H;
    }
    newNode->value=val;

    if(n==1 || H==NULL){
        newNode->ptr=H;
        H = newNode;
    }
    else if(n==2){
        while(temp->ptr != NULL)
            temp=temp->ptr;
        newNode->ptr=NULL;
        temp->ptr=newNode;
    }
    else {
        if(H==NULL || val <= (H->value)){ // here H== NULL is only for direct function making purpose otherwise it is not important
        //this condition for inserting value at front
        newNode->ptr = H;
        H=newNode;
        }
        else{
        //insert at other place
        temp=H;
        while(temp->ptr != NULL && (temp->ptr)->value < val)
            temp=temp->ptr;
            //Now temp points to a Node after which new Node will be inserted.
        newNode->ptr = temp->ptr;
        temp->ptr = newNode;
        }
    }

    return H;
}

struct Node* deleteValue(struct Node* H,int n){
    struct Node* nodeDeleted,*temp=H;
    if(H==NULL){
        printf("List is empty\n");
        return H;
    }
    if(n==4){
        nodeDeleted = H;
        H = H->ptr;
        free(nodeDeleted);
    }
    else{

        if(H->ptr == NULL){
            //condition for only Node
            nodeDeleted = H;
            H = H->ptr;
            free(nodeDeleted);
        }
        else{
            while((temp->ptr)->ptr != NULL)
                temp= temp->ptr;
            nodeDeleted= temp->ptr;
            temp->ptr = NULL;
            free(nodeDeleted);
        }
    }
    return H;
}

struct Node* deleteValueZ(struct Node* H,int val){
    struct Node* nodeDeleted,*temp=H;

    if(H==NULL){
        printf("List is empty\n");
        return H;
    }
    if(H->value ==val){
        //condition for only node
        //in other case we find out our value from sitting at previous Node ,here there is only single Node
        nodeDeleted = H;
        H = H->ptr;
        free(nodeDeleted);
        return H;
    }

    while((temp->ptr != NULL) && (temp->ptr)->value != val)
        temp = temp->ptr;

    if(temp->ptr == NULL)
        printf("Number not found\n");
    else{
        nodeDeleted = temp->ptr;
        temp->ptr = (temp->ptr)->ptr;
        free(nodeDeleted);
    }

    return H;
}

void display(struct Node *H){
    struct Node* temp;
    temp=H;

    if(temp==NULL){
        printf("Your list is empty\n");
        return;
    }
    while(1){
        printf("%d\t",(temp->value));

        if(temp->ptr==NULL)
            break;
        else
            temp=temp->ptr;

    }
    printf("\n");
}

void deallocate(struct Node* H){
    struct Node* temp;
    while(H!=NULL){
        temp=H;
        H = H->ptr;
        free(temp);
    }
}

void main(){
    int val,n;
    struct Node *Head;
    Head=NULL;

    printf("Enter 1 for insert at front \n");
    printf("Enter 2 for insert at end \n");
    printf("Enter 3 for insert in order \n");
    printf("Enter 4 for delete from front \n");
    printf("Enter 5 for delete from end \n");
    printf("Enter 6 for delete specific value \n");
    printf("Enter 7 for display list \n");
    printf("Enter 8 for exit \n");
    scanf("%d",&n);

    while(1){
        switch(n){
        case 1:
        case 2:
        case 3:
            printf("Enter the value you want to inserted\n");
            scanf("%d",&val);
            Head=insertValue(Head,val,n);
            break;
        case 4:
        case 5:
            Head=deleteValue(Head,n);
            break;
        case 6:
            printf("Enter the value you want to be deleted \n");
            scanf("%d",&val);
            Head =deleteValueZ(Head,val);
            break;
        case 7:
            display(Head);
            break;
        case 8:
            deallocate(Head);
            exit(0);
        default:
            printf("Enter correct number\n");

        }
        printf("Enter the operation number: \n");
        scanf("%d",&n);

    }

}
