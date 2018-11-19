#include<stdio.h>

void main(){
    int i,j,n,min,temp;

    printf("How many numbers are there in your list:\n");
    scanf("%d",&n);
    int a[n];

    printf("Enter the unsorted list of numbers:\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);

    // One by one move boundary of unsorted sub array
    for(i=0;i<n-1;i++){
        // Find the minimum element in unsorted array
        min = i;
        for(j=i+1;j<n;j++){
            if(a[j]<a[min])
                min = j;
        }

        // Swap the found minimum element with the first element
         temp = a[min];
         a[min] = a[i];
         a[i] = temp;
    }

    for(i=0;i<n;i++)
        printf("%d ",a[i]);
}
