//only for basic idea of merging two sorted arrays
#include<stdio.h>

void main(){
    int i,j,k,a[5],b[5],r[10];
    printf("Enter the two sorted array of 5-5 elements.\n");
    for(k=0;k<5;k++)
        scanf("%d",&a[k]);
    for(k=0;k<5;k++)
        scanf("%d",&b[k]);

    i=0,j=0;
/*
    here L[n1] & R[n2] are two sorted arrays
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            a[k] = L[i];
            i++;
        }
        else
        {
            a[k] = R[j];
            j++;
        }
        k++;
    }

    //* Copy the remaining elements of L[], if there are any /
    while (i < n1)
    {
        a[k] = L[i];
        i++;
        k++;
    }

    //* Copy the remaining elements of R[], if there are any /
    while (j < n2)
    {
        a[k] = R[j];
        j++;
        k++;
    }
}
*/
    for(k=0;k<10;k++){
        if(a[i]<b[j]){
            r[k]=a[i];
            i++;
        }
        else{
            r[k] = b[j];
            j++;
        }
        if(i==5 || j==5)
            break;
    }
    k=k+1;
    if(i=5){
        while(k!=10){
            r[k++]= b[j++];
        }
    }else{
        while(k!=10){
            r[k++]= b[i++];
        }
    }
    for(k=0;k<10;k++){
        printf("%d ",r[k]);
    }
}
