#include<stdio.h>
#include<stdlib.h>

struct node{
	int  value;
	struct node *link;
	};

struct node* insertAtFront(struct node* head,int val){
	struct node* newNode;
	newNode = (struct node*)malloc(sizeof(struct node));
	if(newNode == NULL){
        printf("new block is not creating\n");
        return head;
	}

	newNode->value = val;
    newNode->link = head; //here we don't check whether head is NULL or Not.
    head = newNode;

	return head;
}

void insertAtSpecific(struct node * head,int pval,int val){
    struct node* newNode,*temp = head;
	newNode = (struct node*)malloc(sizeof(struct node));
	if(newNode == NULL){
		printf("new block is not creating\n");
        return;
	}

	newNode->value = val;

	while(temp->value != pval)
            temp = temp->link;

    newNode->link = temp->link;
    temp->link = newNode;

}

void insertAtEnd(struct node** head,int val){
    struct node *newNode,*temp;
    temp = (*head);

	newNode = (struct node*)malloc(sizeof(struct node));
	if(newNode == NULL){
		printf("new block is not creating\n");
        return;
	}

	newNode->value = val;

	if((*head) == NULL){
        newNode->link = NULL;
        (*head) = newNode;
        return;             // this line is  most important. check it by removing it.
	}

	while(temp->link != NULL)
        temp= temp->link;

    temp->link = newNode;
    newNode->link = NULL;

}

void insert_Order(struct node** head,int val){
    struct node* newNode,*temp = *head;
	newNode = (struct node*)malloc(sizeof(struct node));
	if(newNode == NULL)
		printf("new block is not creating\n");

	newNode->value = val;


	if(*head == NULL || val <= (*head)->value){
            newNode->link = *head;
            *head = newNode;
	}
	else{
        while(temp->link != NULL && temp->link->value <val){
            temp= temp->link;
        }

        newNode->link = temp->link;
        temp->link = newNode;

	}
}

void display(struct node *head){
    struct node *temp=head;

    if(temp==NULL){
        printf("Your list is empty\n");
        return;
    }

    while(temp != NULL){
        printf("%d ",temp->value);
        temp = temp->link;
    }
}

void main(){

	struct node * head;
	head= NULL;

	int n,val,pval;

	printf("Enter 1 for insert at front:\n");
	printf("Enter 2 for insert at end \n");
	printf("Enter 3 for insert at specific value :\n");
    printf("Enter 4 for insert in order \n");
	printf("Enter 5 for display\n");
	printf("Enter 6 for Exit \n");
	scanf("%d",&n);

	while(n!=6){
	switch(n){
	case 1:
		printf("Enter the value  you want:\n");
		scanf("%d",&val);
		head = insertAtFront(head,val);
		break;
	case 2:
	    printf("Enter the value :\n");
		scanf("%d",&val);
		insertAtEnd(&head,val);
		break;

	case 3:
	    printf("Enter after which value you want to be entered new value:\n");
		scanf("%d",&pval);
		printf("Enter the value you want to be inserted:\n");
		scanf("%d",&val);
		insertAtSpecific(head,pval,val);
		break;

    case 4:
        printf("Enter the value:\n");
        scanf("%d",&val);
        insert_Order(&head,val);
        break;
	case 5:
		display(head);
		break;
	default:
		printf("Enter value between 1 to 6:\n");

	}
	printf("Enter which type of operation you want to do again\n");
	scanf("%d",&n);
    }
}
