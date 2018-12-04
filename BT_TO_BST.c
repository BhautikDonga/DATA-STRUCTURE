#include<stdio.h>
#include<stdlib.h>

struct treeNode{
    int value;
    struct treeNode *lptr;
    struct treeNode *rptr;
};

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

void inorder(struct treeNode * r){
    if(r != NULL){
        inorder(r->lptr);
        printf("%d ",r->value);
        inorder(r->rptr);
    }
}

int main(){
    int n,val,bt[10]={0},i;
    struct treeNode *root;
    root = NULL;

    printf("ENter how many node are there in your Binary tree\n");
    scanf("%d",&n);
    printf("Insert the value of binary tree in level order\n");
    for(i=0;i<n;i++)
        scanf("%d",&bt[i]);

    for(i=0;i<n;i++)
        insert_val(&root,bt[i]);

    printf("The inorder traversal of BST is\n");
    inorder(root);

    return 0;
}
