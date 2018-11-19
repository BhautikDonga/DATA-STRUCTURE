#include<stdio.h>

void merge(int a[], int s, int m, int e) {
    int i, j, k;
    int n1 = m - s + 1;
    int n2 =  e - m;

    /* create temp arrays */
    int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = a[s + i];
    for (j = 0; j < n2; j++)
        R[j] = a[m + 1+ j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = s; // Initial index of merged subarray
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
    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        a[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        a[k] = R[j];
        j++;
        k++;
    }
}


void mergeSort(int a[],int s,int e){//s = starting index && e= ending index
    int m;
    if(s<e){
        //m = (s+e-1)/2  both are same
        m = (s+e)/2; // m= middle index

        mergeSort(a,s,m);
        mergeSort(a,m+1,e);

        merge(a,s,m,e);
    }

}
void main(){
    int i,n;
    printf("Enter the size of list\n");
    scanf("%d",&n);
    int a[n];

    printf("Enter the unsorted list of numbers:\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);

    mergeSort(a,0,n-1); //(array,starting index, ending index)
    for(i=0;i<n;i++)
        printf("%d ",a[i]);

}
