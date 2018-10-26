#include<stdio.h>

void TowerOfHanoi(char,char ,char,int);
int i=1;

void main(){
    int n;
    printf("Enter the number of rings: \n");
    scanf("%d",&n);

    TowerOfHanoi('F','T','U',n);

}

void TowerOfHanoi(char F,char T,char U,int n){
    if(n==1){
        printf("step %d :Move %d from %c to %c\n",i++,n,F,T);
    }else{
        TowerOfHanoi(F,U,T,n-1);
        printf("Step %d :Move %d from %c to %c\n",i++,n,F,T);
        TowerOfHanoi(U,T,F,n-1);
    }
}
