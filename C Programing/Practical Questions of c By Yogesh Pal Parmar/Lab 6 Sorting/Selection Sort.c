#include<stdio.h>
void selectionSort(int arr[], int n){
	int temp =0;
	int i;
	int j;
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(arr[i] > arr[j]){
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
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
	selectionSort(arr,n);
	
}