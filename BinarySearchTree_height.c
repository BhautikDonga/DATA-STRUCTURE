//program for find height of binary tree
// for any node its works as a root node for its subtree and we can find height for its and depth for its.
// depth of a node is a number of a edges in path from root to that node.
#include<stdio.h>
#include<stdlib.h>

struct treeNode{
    int value;
    struct treeNode *left;
    struct treeNode *right;
};

void insert_val(struct treeNode ** root,int val){
    struct treeNode * newNode,*temp;
    temp = (*root);
    newNode = (struct treeNode*)malloc(sizeof(struct treeNode));

    if(newNode == NULL)
        printf("Error in malloc creation");

    newNode->value = val;
    newNode->left = NULL;
    newNode->right = NULL;

    if((*root) == NULL){
        (*root) = newNode;
        return;
    }
    while(1){
        if(val < temp->value){
            if(temp->left == NULL){
                temp->left = newNode;
                break;
            }
            temp = temp->left;
        }
        else{
            if(temp->right == NULL){
                temp->right = newNode;
                break;
            }
            temp = temp->right;
        }
    }

}

int height_tree(struct treeNode *r){
    int htl,htr;
    if(r == NULL)
        return 0;
    else{
         /* compute the depth of each subtree */
        htl = height_tree(r->left);
        htr = height_tree(r->right);
        /* use the larger one */
        return ((htl > htr)? htl : htr ) + 1;
    }
}

void main(){
    int n,val;
    struct treeNode *root;
    root = NULL;

    printf("Enter 1 if you want to insert number:\n");
    scanf("%d",&n);
    while(n==1){
        printf("Enter the number you want to insert\n");
        scanf("%d",&val);
        insert_val(&root,val);
        printf("Enter 1 if you want to insert number again\n");
        scanf("%d",&n);
    }
    printf("The height of the tree is %d",height_tree(root));
}
