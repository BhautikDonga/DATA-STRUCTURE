#include<stdio.h>

int main(){
    int N,i,j,k;
    scanf("%d",&N);

    for(i=2;i<=N;i++){
        k=0;
        for(j=2;j<i;j++){

            if(i%j==0){
                k=1;
            }
        }

        if(k==0){
            printf("%d ",i);
        }

    }
}
