#include<stdio.h>

void main(){
    int i,j,key,n;
    printf("How many numbers are there in your list\n");
    scanf("%d",&n);

    int a[n];
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);

    printf("Enter the unsorted list of numbers:\n");
    for(i=1;i<n;i++){// i will loop for n-1 times
        key = a[i];
        j=i-1;

      /* Move elements of arr[0..i-1], that are
          greater than key, to one position ahead
          of their current position */

        while (j >= 0 && a[j] > key){
           a[j+1] = a[j];
           j = j-1;
        }
        a[j+1] = key;
    }

    for(i=0;i<n;i++)
        printf("%d ",a[i]);
}

/*  method -2:
	for(int i=0; i<n; i++)
	{
		min_idx = i;
		for(int j=i; j<n; j++)
    	{
			if(arr[j] < arr[min_idx])
      		{
				min_idx = j;
	   		}
	  	}

    	temp = arr[min_idx];
		arr[min_idx] = arr[i];
		arr[i]= temp;
	}
*/
/* method -3:
// Recursive function to sort an array using
// insertion sort
void insertionSortRecursive(int arr[], int n)
{
    // Base case
    if (n <= 1)
        return;

    // Sort first n-1 elements
    insertionSortRecursive( arr, n-1 );

    // Insert last element at its correct position
    // in sorted array.
    int last = arr[n-1];
    int j = n-2;

    // Move elements of arr[0..i-1], that are
    //greater than key, to one position ahead
    //of their current position
    while (j >= 0 && arr[j] > last)
    {
        arr[j+1] = arr[j];
        j--;
    }
    arr[j+1] = last;
}
*/
