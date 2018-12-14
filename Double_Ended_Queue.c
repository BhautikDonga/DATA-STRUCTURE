#include<stdio.h>
#define N 5

int F=-1,R=-1;

void main(){
    int q[N];
    int val,item;

    printf("Enter 1 for insert at front\n");
    printf("Enter 2 for insert at rear\n");
    printf("Enter 3 for delete from front\n");
    printf("Enter 4 for delete from rear\n");
    printf("Enter 5 for display \n");
    printf("Enter 6 for EXIT\n");
    scanf("%d",&n);

    switch(n){
        case 1;
            printf("Enter value you want to be inserted: \n");
            scanf("%d",&val);
            insertatfront(q,val);
            break;
        case 2:
            printf("Enter value you want to be inserted: \n");
            scanf("%d",&val);
            insertatrear(q,val);
            break;
        case 3:
            item = f_delete(q);
            printf("%d is deleted\n",item);
            break;

        case 4:
            item = r_delete(q);
            printf("%d is deleted\n",item);
            break;

        case 5:
            display();
            break;


    }
}
