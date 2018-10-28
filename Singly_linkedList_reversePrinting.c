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

void reverseDisplay(struct node* head){
    struct node* temp,*ptemp;
}

/*void reverseDisplay(struct node* head){
    if(head->link != NULL)
        reverseDisplay(head->link);
    printf("%d ",head->value);
}*/

/*void reverseDisplay(struct node* head){
    if(head == NULL)
        return;
    reverseDisplay(head->link);
    printf("%d ",head->value);
}*/

void main(){
    struct node* head = NULL;
    int val,n;

    printf("Enter 1 for insert value\n");
    printf("Enter 2 for display list\n");
    printf("Enter 3 for reverse display\n");
    printf("Enter 4 for EXIT\n");
    scanf("%d",&n);

    while(n!= 4){
    switch(n){
    case 1:
        printf("Enter value:\n");
        scanf("%d",&val);
        head = insertAtFront(head,val);
        break;
    case 2:
        display(head);
        break;
    case 3:
        reverseDisplay(head);
        break;
    default:
        printf("Enter value between 1 to 4\n");
    }

    printf("Enter 1 to 4 as per your choise operation\n");
    scanf("%d",&n);
    }

}
