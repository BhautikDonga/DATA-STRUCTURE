/*How many different Unlabeled Binary Trees can be there with n nodes?
	T(n) = (2n)! / (n+1)!n!
	Number of Binary Search Trees (BST) with n nodes is also same as number of unlabeled trees.
**How many labeled Binary Trees can be there with n nodes?
	Number of Labeled Tees = (Number of unlabeled trees) * n!
                       = [(2n)! / (n+1)!n!]  × n!
*/
/*The number of binary search trees can be seen as a recursive solution. i.e.,
Number of binary search trees = (Number of Left binary search sub-trees) * (Number of Right binary search sub-trees) * (Ways to choose the root)*/
/*Number of Binary Search Trees (BST) with n nodes is also same as number of unlabeled trees.
The reason for this is simple, in BST also we can make any key as root, If root is i'th key in
 sorted order, then i-1 keys can go on one side and (n-i) keys can go on other side.*/
 /*simple recursion function for counting number of possible trees will be:
int count(int N){
    if(N==0||N==1)
        return(1);

    for(int i=1;i<=N;i+=1){
        left=count(i-1);
        right=count(N-i);
        sum=sum+left*right;
    }
    return sum;
}*/
#include<stdio.h>

long factorial(int n){
    if(n==0)
        return 1;
    else
        return n*factorial(n-1);
}

void main(){
    int n;
    long ans;
    char ch;
    printf("Enter how many nodes in  the tree: \n");
    scanf("%d",&n);
    printf("Are nodes with labeled y/n ?\n");
    //ch = getchar(); //getch() in conio whereas getchar is in stdio.h
    scanf(" %c",&ch);

    if(ch=='Y' || ch=='y'){
        ans = factorial(2*n) / factorial(n+1);
    }
    else{
        ans = factorial(2*n) / (factorial(n+1)*factorial(n));
    }
    printf("Total number of trees possible are %ld",ans);
}
