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

struct node* deleteFront(struct node* head){
    struct node* nodeToBeDeleted;
    nodeToBeDeleted = head;

    if(head->link == NULL){
        free(head);
        printf("Now List became empty\n");
        return NULL;
    }
    head = head->link;
    free(nodeToBeDeleted);
    return head;

}

void deleteEnd(struct node** head){
    struct node* temp = *head;

    if(temp->link == NULL){
        free(temp);
        *head = NULL;
        printf("Now your List is empty\n");
        return;
    }
    while(temp->link->link != NULL)
        temp = temp->link;

    free(temp->link);
    temp->link = NULL;
}

struct node* deleteSpecific(struct node* head,int val){
    struct node* nodeToBeDeleted,*temp = head;

    if(head==NULL){
        printf("List is empty\n");
        return head;
    }

    if(head->link == NULL && head->value == val){
        //condition for only node
        //in other case we find out our value from sitting at previous Node ,here there is only single Node
        nodeToBeDeleted = head;
        head = head->link;
        free(nodeToBeDeleted);
        return head;
    }

    while((temp->link != NULL) && (temp->link->value != val) )
        temp = temp->link;

    if(temp->link == NULL){
        printf("Entered value is not found\n");
    }
    else{
    nodeToBeDeleted = temp->link;
    temp->link = temp->link->link;
    free(nodeToBeDeleted);
    }

    return head;
};

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

	int n,val;

	printf("Enter 1 for insert\n");
	printf("Enter 2 for delete from front \n");
	printf("Enter 3 for delete from end\n");
    printf("Enter 4 for delete specific value \n");
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
		head = deleteFront(head);
		break;

	case 3:
	    deleteEnd(&head); //pass address , for if there is only node to be deleted use
		break;

    case 4:
        printf("Enter the value:\n");
        scanf("%d",&val);
        head = deleteSpecific(head,val);
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

