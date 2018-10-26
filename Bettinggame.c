#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int n,b,r,*a;

void start(){
    srand(time(0));
    int a;
    a=rand()%3;
    //a = (int*)malloc(sizeof(int));
    //a[0]=rand()%3;
    //a[1]= rand()%3;
    //a[2]= rand()%3;


    if(n>0){

        printf("you have currently $%d \n",n);
        printf("enter the bet ammount $");
        scanf("%d",&b);
        if(b<=n){
        printf("find the place of queen[chose 1,2,3] : ");
        scanf("%d",&r);
        if(a==(r-1) ){
            printf("congrulations you win!\n");
            n=n-b+(3*b);
            printf("now you have $%d\n",n);
            }
        else{
            printf("Better luck Next time\n");
            n=n-b;
            printf("now you have $%d \n",n);
        }
        }else{
            printf("you have only $%d and you Bet $%d \n",n,b);

        }

    }
    else{
            printf("you are not eligible to play game \n you have no money\n");
        }
       // free(a);

}
int main(){
    int f;
    char m;
    printf("BETTING GAME\n");
    printf("rules : \n");
    printf("1) you have to chose between 1 to 3 \n");
    printf("2) you are allow to play till you have $0 \n");
    printf("3) if you will win then you will get 3*(BET AMOUNT)\n\n\n");
    printf("how many amount you have $");
    scanf("%d",&n);

    f=n;
    printf("   GAME START    \n");

    printf("you want to play game(y/n): \n");
    scanf("%c",&m);

    while(n!=0 && m !='n'){
    start();
    printf("you want to play game again!(y/n): \n");
    scanf("%c",&m);
    }

    printf("\nyou come with $%d\n",f);
    printf("now you have $%d\n",n);
    printf("thank you for play!\n");
    return 0;

}


