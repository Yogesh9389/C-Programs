#include<stdio.h>
void insertionSort(int arr[], int n){
	for(int i=0;i<n;i++){
		int current = arr[i];
		int j = i-1;
		while(arr[j] > current && j>=0){
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = current;
	}
	printf("\n");
	for(int i=0; i<n; i++){
		printf(" %d", arr[i]);
	}
}


void main(){
	printf("Yogesh Pal Parmar MCA 2B 70");
	int n;
	printf("\nEnter a value : ");
	scanf("%d",&n);
	int arr[n];
	int i;
	for(i=0; i<n; i++){
		scanf("%d", &arr[i]);
	}
	insertionSort(arr,n);
	
}