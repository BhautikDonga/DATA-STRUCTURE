//for binary tree, traversal by level order method.

#include<stdio.h>
#include<stdlib.h>

struct treeNode{
    int value;
    struct treeNode *lptr;
    struct treeNode *rptr;
};

struct queueNode{
    struct treeNode * data;
    struct queueNode * ptr;
};
struct queueNode * front= NULL;
struct queueNode * rear = NULL;

void insert_queue(struct treeNode* value){
    struct queueNode* newNode;
    newNode = (struct queueNode*) malloc(sizeof(struct queueNode));
    if(newNode == NULL){
        printf("Malloc is failed\n");
        return;
    }

    newNode->data = value;
    newNode->ptr = NULL;
    if(front == NULL)
        front = rear = newNode;
    else{
        rear->ptr = newNode;
        rear = newNode;
    }
}

void dequeue(){
    struct queueNode * temp;
    //we dont have to put front = null condition because dequeue is not called when front = null.
    temp = front->ptr;
    free(front);
    front = temp;
}

void levelOrder_traversal(struct treeNode* r){
    if(r == NULL){
        printf("Tree is Empty\n");
        return;
    }

    insert_queue(r);

    while(front != NULL){
        printf("%d ",front->data->value);

        if(front->data->lptr != NULL) insert_queue(front->data->lptr);
        if(front->data->rptr != NULL) insert_queue(front->data->rptr);

        dequeue();
    }

}

struct treeNode* insert_val(struct treeNode * root,int val){
    struct treeNode * newNode,*temp;
    temp = root;
    newNode = (struct treeNode *)malloc(sizeof(struct treeNode));
    if(newNode==NULL){
        printf("Error in malloc\n");
        return root;
    }

    newNode->value = val;
    newNode->lptr = NULL;
    newNode->rptr = NULL;

    if(root == NULL){
        root = newNode;
        return root;
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
    return root;
}


void main(){
    int n,val;
    struct treeNode *root;
    root = NULL;

    printf("Enter 1 for insert value\n");
    printf("Enter 2 for level order traversal\n");
    printf("Enter 3 for EXIT\n");
    scanf("%d",&n);

    while(n!=3){
    switch(n){
    case 1:
        printf("Enter the value you want to insert\n");
        scanf("%d",&val);
        root = insert_val(root,val);
        break;
    case 2:
        levelOrder_traversal(root);
        break;
    default:
        printf("Enter perfect value:\n");
    }
    printf("Enter which type of operation you want to do again\n");
    scanf("%d",&n);
    }

}
