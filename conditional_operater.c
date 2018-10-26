// find maximum from three number
#include<stdio.h>

int main(){
    int max,a,b,c;

    scanf("%d %d %d",&a,&b,&c);

    max= (a>b)? ((a>c) ? a : c) : ((b>c) ? b : c);
    printf("max number is %d",max);
    return 0;
     }
