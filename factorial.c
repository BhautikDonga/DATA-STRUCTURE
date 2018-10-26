#include<stdio.h>

long factorial(int);

void main(){
    int n;
    long fact;
    printf("Enter the number for factorial: \n");
    scanf("%d",&n);
    fact=factorial(n);
    printf("The factorial of %d is : %ld",n,fact);
}

long factorial(int n){
    if(n==1)
        return 1;
    else
        return n* factorial(n-1);
}
