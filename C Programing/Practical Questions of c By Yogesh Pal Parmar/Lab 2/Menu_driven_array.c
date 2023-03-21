#include<stdio.h>
// traversing an array
int traverseArray(int arr[], int n)
{
	int i;
	for(i=0; i<n; i++)
	{
		printf("\n element at %d = %d", i, arr[i]);
	}
	return 0;
}
// inserting in an array
int insertArray(int arr[],int n,int pos,int num)
{
	int i;
	for(i=n-1;i>=pos;i--)
	{
		arr[i] = arr[i-1];
	}			
	arr[pos] = num;
	for (i=0; i<n; i++)
	{
		printf("\nNew array is : %d", arr[i]);
	}
	return 0;
}
// delete from the array
int deleteArray(int arr[], int n, int p)
{
	int i;
	if (p >=n)
	{
		printf("\nElement not found");
		return 0;
	}
	for(i=p; i<n;i++)
	{
		arr[i] = arr[i+1];
	}
	n--;
	for(i=0;i<n;i++)
	{
		printf("\nNew array is : %d", arr[i]);
	}
	return 0;
}
//main method
int main()
{
	int n;
	int i;
	int ch;
	printf("\n Enter size of array : ");
	scanf("%d", &n);
	int arr[n];
	/*for(i=0; i<n; i++)
	{
		scanf("%d", &arr[i]);
	}*/
	printf("\nEnter a choice : ");
	scanf("%d", &ch);
	switch (ch)
	{
		case 1: // traverse array
			traverseArray(arr,n);
		break;
		case 2:  // insert element in array at pos
			n++;
			int pos;
			int num;
			printf("\nEnter the position to insert :");
			scanf("%d", &pos);
			printf("\nEnter the number to insert : ");
			scanf("%d", &num);
			insertArray(arr,n,pos,num);
		break;
		case 3: // delete element from array
			printf("\nEnter position to delete : ");
			int p;
			scanf("%d", &p);
			deleteArray(arr,n,p);
		break;
		/*case 4:
			searchingArray(arr);
			break;
		case 5:
			mergingArray(arr);
			break;
		case 6:
	 		updationArray(arr);
		break;*/
		default:
			printf("\nInvalid choice");
	}
	
}

