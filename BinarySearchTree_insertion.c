//Recursively tree traversal by inorder,preorder,and postorder

#include<stdio.h>
#include<stdlib.h>


struct treeNode{
    int value;
    struct treeNode *lptr;
    struct treeNode *rptr;
};


//inserting value according to rule that all value which is greater than root value is goes right branch and small value in left branch.
void insert_val(struct treeNode ** root,int val){
    struct treeNode * newNode,*temp;
    temp = (*root);
    newNode = (struct treeNode *)malloc(sizeof(struct treeNode));

    if(newNode==NULL){
        printf("error in malloc\n");
    }

    newNode->value = val;
    newNode->lptr = NULL;
    newNode->rptr = NULL;

    if((*root) == NULL){
        (*root) = newNode;
        return;
    }

    while(1){
        if(val < temp->value){
            if(temp->lptr == NULL){
                temp->lptr = newNode;
                break;
            }
            temp = temp->lptr;
        }
        else{
            if(temp->rptr == NULL){
                temp->rptr = newNode;
                break;
            }
            temp = temp->rptr;
        }
    }
}

/*
called as: root = insert(root,value);
function defination:
    struct treeNode* insert(root ,v){

        if(root == NULL){
            struct treeNode* newNode;
            newNode = (struct treeNode*)malloc(sizeof(struct treeNode));
            newNode->value = v;
            newNode->lptr = newNode->rptr = NULL;
            return newNode;
        }

        if(v < root->value)
            root->left = insert(root->left,v)
        else
            root->right = insert(root->right,v)

        return root;
    }
*/

void preorder(struct treeNode * r){
    if(r != NULL){
        printf("%d ",r->value);
        preorder(r->lptr);
        preorder(r->rptr);
    }
}

void inorder(struct treeNode * r){
    if(r != NULL){
        inorder(r->lptr);
        printf("%d ",r->value);
        inorder(r->rptr);
    }
}

void postorder(struct treeNode * r){
    if(r != NULL){
        postorder(r->lptr);
        postorder(r->rptr);
        printf("%d ",r->value);
    }
}

int main(){
    int n,val;
    struct treeNode *root;
    root = NULL;

    printf("Enter 1 for insert\n");
    printf("Enter 2 for traverse preorder\n");
    printf("Enter 3 for traverse inorder\n");
    printf("Enter 4 for traverse postorder\n");
    printf("Enter 5 for EXIT\n");
    scanf("%d",&n);

    while(n!=5){
    switch(n){
    case 1:
        printf("Enter the value you want to be insert:\n");
        scanf("%d",&val);
        insert_val(&root,val);
        break;
    case 2:
        preorder(root);
        break;
    case 3:
        inorder(root);
        break;
    case 4:
        postorder(root);
        break;
    default:
        printf("Enter proper value\n");
    }
    printf("Enter which operation you want to do again\n");
    scanf("%d",&n);
    }
    return 0;
}
