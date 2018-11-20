//AVL Tree insertion and Deletion.
#include<stdio.h>
#include<stdlib.h>

struct AVLNode{
	int value,height;
	struct AVLNode* left;
	struct AVLNode* right;
};

int getHeight(struct AVLNode* r){
	int htl,htr;
    	if(r == NULL)
        	return -1;
    	else{
         /* compute the depth of each subtree */
        	htl = getHeight(r->left);
        	htr = getHeight(r->right);
        /* use the larger one */
        	return ((htl > htr)? htl : htr ) + 1;
        }
}

int getBalance(struct AVLNode* r){
	return getHeight(r->left) - getHeight(r->right);
}

struct AVLNode* singleRotateLeft(struct AVLNode* p){
	struct AVLNode* RC = p->right;
	p->right = RC->left ;
	RC->left = p;

	p->height = getHeight(p);
	RC->height = getHeight(p);
	return RC;
}

struct AVLNode* singleRotateRight(struct AVLNode* p){
	struct AVLNode* LC = p->left;
	p->left = LC->right ;
	LC->right = p;

	p->height = getHeight(p);
	LC->height = getHeight(p);
	return LC;
}

struct AVLNode* doubleRotateLeftRight(struct AVLNode* p){
	struct AVLNode * LC;
	LC = p->left;
	p->left = singleRotateLeft(p->left);
	p = singleRotateRight(p);

	return p;
}

struct AVLNode* doubleRotateRightLeft(struct AVLNode* p){
	struct AVLNode * RC;
	RC = p->right;
	p->right = singleRotateRight(p->right);
	p = singleRotateLeft(p);

	return p;
}

struct AVLNode* findMin(struct AVLNode* ptr){
	/* follow left branch */
	while( ptr->left != NULL)
		ptr = ptr->left;
	return ptr;
}


struct AVLNode* insert_val(struct AVLNode* r,int val){
	if(r == NULL){
		struct AVLNode* newNode;
		newNode = (struct AVLNode*)malloc(sizeof(struct AVLNode));
		if(newNode == NULL){
			printf("Error in malloc\n");
			return r;
		}
		newNode->value = val;
		newNode->height = 0;
		newNode->left = newNode->right = NULL;
		return newNode;
	}
	if(val < r->value){
		r->left = insert_val(r->left,val);
		if(getBalance(r) == 2){
			if(val < r->left->value)
				r = singleRotateRight(r);
			else
				r = doubleRotateLeftRight(r);
		}
	}
	else{//val >=r->value
		r->right = insert_val(r->right,val);
		if(getBalance(r) == -2){
			if(val >= r->right->value)
				r = singleRotateLeft(r);
			else
				r = doubleRotateRightLeft(r);
		}
	}
	r->height = getHeight(r);
	return r;
}

struct AVLNode* delete(struct AVLNode* r,int val){
	struct AVLNode* temp;
	int balance;

	if(r == NULL)
		return r;

	if(val < r->value)
		r->left = delete(r->left,val);
	else if(val > r->value)
		r->right = delete(r->right,val);
	else{
		/*Here we don't have to write condition for 0 child.because conition for 1 child already return NULL to other.*/
		if(r->left == NULL){
			temp = r->right;
			free(r);
			r = temp;
		}
		else if(r->right == NULL){
			temp = r->left;
			free(r);
			r = temp;
		}
		else{ // Node with 2 child deleted.
			temp = findMin(r->right); //get inOrderSuccessor
			r->value = temp->value;
			r->right = delete(r->right , temp->value);
		}

		/* This is only new part in BST */
		if(r == NULL)
			return r;
		if(getBalance(r) == 2){
			if(getBalance(r->left) >= 0)/* Left - Left*/
					return singleRotateRight(r);
			else/* Left - Right */
					return doubleRotateLeftRight(r);
		}
		if(getBalance(r) == -2){
			if(getBalance(r->right) <= 0) /* Right - Right*/
				return singleRotateLeft(r);
			else /* Right - Left */
				return doubleRotateRightLeft(r);
		}

		r->height = getHeight(r);
		return r;

	}
}

void display(struct AVLNode* r){
	if(r!= NULL){
		display(r->left);
		printf("%d ",r->value);
		display(r->right);
	}
}

void main(){
	int n,val;
	struct AVLNode* root = NULL;
	printf("Enter 1 for insert value:\n");
	printf("Enter 2 for delete the value\n");
	printf("Enter 3 for display the AVL tree in inorder:\n");
	printf("enter 4 for EXIT:\n");
	scanf("%d",&n);

	while(n!=4){
	switch(n){
		case 1:
			printf("Enter the value:\n");
			scanf("%d",&val);
			root = insert_val(root,val);
			break;
		case 2:
			printf("Enter the value you want to deleted\n");
			scanf("%d",&val);
			root = delete(root,val);
			break;
		case 3:
		    printf("The inorder list of AVLTree is: \n");
			display(root);
			printf("\n");
			break;
		default:
			printf("Enter value between 1 to 4\n");
	}
	printf("\nEnter 1)Insert 2)delete 3)display 4)Exit :\n");
	scanf("%d",&n);
	}
}
