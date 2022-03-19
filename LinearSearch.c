#include<stdio.h>
#include<stdlib.h>
 int linear_search(int [], int, int);

int main(){
	int A[100], i, n, loc, d;
	printf("\nEnter the size of the list: ");
	scanf("%d", &n);
	if (n>100){
		printf("\nSize should be less or equal to 100");
		exit(0);
}
	printf("\nEnter the element in the array");
	for(i=0; i<n;i++){
		printf("\nEnter A[%d]: ",i);
		scanf("%d", &A[i]);
}
	printf("\nEnter the data that need to be searched: ");
	scanf("%d",&d);
	loc=linear_search(A, n, d);
	if (loc==-1){
		printf("\nThe data %d is not present in the array",d);
	}
	else{
		printf("\n The data %d is present at position %d of the aray",d, loc);
}
}

int linear_search(int A[], int n, int d){
	int i;
	for (i=0; i<n;i++){
		if (A[i]==d){
			return i;
	}
}
	return -1;
}

