#include<stdio.h>
void bubbleSort(int arr[], int n){
	int count =1;
	while(count < n){
		for(int i=0;i<n-count;i++){
			if(arr[i] > arr[i+1]){
				int temp = arr[i];
				arr[i] = arr[i+1];
				arr[i+1] = temp;
			}
		}
		count++;
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
	bubbleSort(arr,n);
	
}