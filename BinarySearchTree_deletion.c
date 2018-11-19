//in binary search tree node deletion operation.
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

struct treeNode* findMin(struct treeNode* r){
//follow left branch
    while(r->left != NULL)
        r = r->left;
    return r;
}

/* struct treeNode* findMax(struct treeNode* r){
//follow right branch
    while(r->right != NULL)
        r = r->right;
    return r;
}
*/
struct treeNode * delete_val(struct treeNode * r,int val){
    struct treeNode * temp;
    if(r == NULL) return r;

    if(val < r->value)
        r->left = delete_val(r->left,val);
    else if(val > r->value)
        r->right = delete_val(r->right,val);
    else{
         //root->value == val //
        if(r->left == NULL && r->right == NULL){
            free(r);
            return NULL;
        }

        if(r->left == NULL){
            temp = r->right;
            free(r);
            return temp;
        }
        if(r->right == NULL){
            temp = r->left;
            free(r);
            return temp;
        }

        //Root has two children//
        temp = findMin(r->right); //we can also use findMax(r->left);
        r->value = temp->value;
        r->right = delete_val(r->right,temp->value);
    }
    return r;
}

void inorder(struct treeNode * r){
    if(r != NULL){
        inorder(r->left);
        printf("%d ",r->value);
        inorder(r->right);
    }
}

void main(){
    int n,val;
    struct treeNode * root = NULL;

    printf("Enter 1 for Insert value\n");
    printf("Enter 2 for Delete value\n");
    printf("Enter 3 for inorder traversal\n");
    printf("Enter 4 for EXIT\n");
    scanf("%d",&n);

    while(n!=4){
        switch(n){
        case 1:
            printf("Enter value you want to insert: \n");
            scanf("%d",&val);
            insert_val(&root,val);
            break;
        case 2:
            printf("Enter value you want to delete\n");
            scanf("%d",&val);
            root = delete_val(root,val);
            break;
        case 3:
            inorder(root);
            break;
        default:
            printf("Enter proper value\n");
        }
        printf("\nEnter 1/2/3/4\n");
        scanf("%d",&n);
    }
}
