//compare and assign month using array
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct treeNode{
    char month[10];
    struct treeNode * left;
    struct treeNode * right;
};

struct treeNode* insert_month(struct treeNode * root, char mon[]){
    struct treeNode * newNode,*temp = root;
    newNode = (struct treeNode*)malloc(sizeof(struct treeNode));
    if(newNode == NULL){
        printf("Malloc Failed\n");
        return root;
    }
    strcpy(newNode->month,mon);
    newNode->left = newNode->right = NULL;

    if(root == NULL){
        root = newNode;
        return root;
    }

    while(1){
        if(strcmp(temp->month,mon)>0){
        //if(temp->month < root->month){
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
    return root;
}

void preorder_traverse(struct treeNode* root){
    if(root == NULL)
        return;

    printf("%s ",root->month);
    preorder_traverse(root->left);
    preorder_traverse(root->right);
}

void inorder_traverse(struct treeNode* root){
    if(root == NULL)
        return;

    inorder_traverse(root->left);
    printf("%s ",root->month);
    inorder_traverse(root->right);
}

void postorder_traverse(struct treeNode* root){
    if(root == NULL)
        return;

    postorder_traverse(root->left);
    postorder_traverse(root->right);
    printf("%s ",root->month);
}

void main(){
    int n;
    char mon[10];

    struct treeNode * root;
    root = NULL;

    printf("1 for insert the month: \n");
    printf("2 for traversing BST in preorder \n");
    printf("3 for traversing BST in inorder \n");
    printf("4 for traversing BST in postorder \n");
    printf("5 for EXIT\n");
    scanf("%d",&n);
    while(n != 5){
        switch(n){
            case 1:
                printf("Enter the name of month\n");
                scanf("%s",mon);
                root = insert_month(root,mon);
                break;
            case 2:
                preorder_traverse(root);
                printf("\n");
                break;
            case 3:
                inorder_traverse(root);
                printf("\n");
                break;
            case 4:
                postorder_traverse(root);
                printf("\n");
                break;
            default:
                printf("Enter the value between 1 to 5\n");
        }
        printf("\nEnter 1/2/3/4/5 \n");
        scanf("%d",&n);
    }
}
