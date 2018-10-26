#include<stdio.h>
#include<stdlib.h>

void main(){
	int i;
	int *m,*c;
	m= (int*)malloc(5*sizeof(int));
	c= (int*)calloc(5,sizeof(int));
	
	for(i=0;i<5;i++){
		printf("%d %d",m[i],c[i]);
	}
	
	}
