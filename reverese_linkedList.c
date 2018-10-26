#include<stdio.h>
#include<stdlib.h>

struct Node{
    struct Node *ptr;
    int value;
};

struct Node* insertValue(struct Node*H,int val){
    struct Node* newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));

    if(newNode==NULL){
        printf("malloc failed\n");
        return H;
    }

    newNode->value = val;

    if(H == NULL){
	H = newNode;
	H->ptr = NULL;              //here actually no use of if else .we can do it without if else also like,
	}                           // newNode->ptr = H;
    else{                       // H = newNode   this is work for both cases.
	newNode->ptr = H;
	H= newNode;
	}

    return H;
}

struct Node* reverse(struct Node* current){
	struct Node* previous=NULL,*next=NULL;

	while(current != NULL){
		next = current->ptr;
		current->ptr = previous;
		previous = current;
		current = next;
	}
	return previous; //at the end of loop current will consist value NULL and previous will keep value of last node
                        // so we return previous for upgradation of head part.

}

void display(struct Node*head){
	while(head!=NULL){
		printf("%d ",head->value);
		head = head->ptr;
	}
}


void main(){
	int n,val;
	struct Node *head;
	head = NULL;

	printf("Enter 1 for insert value:\n");
	printf("Enter 2 for reverse linked list\n");
	printf("Enter 3 for display\n");
	printf("Enter 4 for EXIT\n");
	scanf("%d",&n);

	while(n!=4){
	switch(n){
	case 1:
		printf("Enter the value\n");
		scanf("%d",&val);
		head = insertValue(head,val);
		break;
	case 2:
		head = reverse(head);
		break;
	case 3:
		display(head);
		break;
	default:
		printf("Enter proper value\n");
	}
	printf("Enter type of operation you want to do again\n");
	scanf("%d",&n);
	}
}

