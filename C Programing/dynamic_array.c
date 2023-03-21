#include <stdio.h>
#include <stdlib.h>
// allcoation using malloc
int allocate_malloc(int* arr, int size)
{
	arr = (int*) malloc(size * sizeof(int));  // using malloc
	if(arr == NULL)
	{
		printf("/n Memory allocation failed :");
	}
	else
	{
		int i ;
    	printf("\n memory allocation successfull :");
    	for( i = 0; i < size; ++i)
    {
        arr[i] = i+1;
    }
	}
 	printf("\n Elements of the array are : ");
 	int j;

	for( j=0 ; j<size; ++j)
	{	
		printf("\n %d", arr[j]);
	}
	return 0;
}
//function to allocate using calloc
int allocate_calloc(int* arr, int size)
{
	arr = (int*)calloc(10, sizeof(int));  // using calloc
	if(arr == NULL)
	{
		printf("\n Memory not allocatd : ");
	}
	else
	{
  		printf("\n Memory succssfully allocatd : ");
    	int i;
		for(i=0; i<size; ++i)
		{
			arr[i] = i+1;	
		}
		printf("\n Elements of the array are : ");
		for(i =0 ; i< size; ++i)
		{
			printf("\n%d",arr[i]);
		}
	}
	return 0;
}
//function to allocate using realloc
int allocate_realloc(int* arr, int size)
{
	arr = (int*)calloc(10, sizeof(int));
	if(arr == NULL)
	{
		printf("\n Memory not allocatd : ");
	}
	else
	{
  		printf("\n Memory succssfully allocatd : ");
    	int i;
		for(i=0; i<size; ++i)
		{
			arr[i] = i+1;	
		}
		printf("\n Elements of the array are : ");
		for(i =0 ; i< size; ++i)
		{
			printf("\n%d",arr[i]);
		}
	}
	int previous_size = size;
	printf("\nRe-enter Size: ");
	scanf("%d", &size);
	int *temp = arr;
	arr = (int*)realloc(arr, size*sizeof(int));
	if(!arr)
	{
		printf("\n Memory allocation failed: ");
		arr = temp;
	}
	else
	{
		printf("\n Memory  successfully allocated: using realloc ");
	}
	//insert new elements 
	int i;
	for(i=previous_size; i<size; ++i)
	{
		arr[i] = i+size;
	}
	printf("\n New elements of the array are : ");
	for( i =0; i<size; i++)
	{
		printf("\n%d",arr[i]);
	}
	return 0; 
}
//main function to call different allocation technique dynamically
int main()
{
	int* arr;
	int size;
	int ch;
	printf("Enter a choice : ");
	scanf("%d", &ch);
switch (ch)
{
case 1:
    printf("Enter the size of the arrar: ");
	scanf("%d", &size);
	allocate_malloc(arr, size); //passing array to malloc function
break;
case 2:
	printf("Enter the size of the arrar: ");
    scanf("%d", &size);
    allocate_calloc(arr, size); // passing array to calloc function
break;
case 3:
	printf("Enter the size of the arrar: ");
    scanf("%d", &size);
    allocate_realloc(arr, size); // passing array to realloc function 
break; 
case 4:
break;
default:
	printf("/n Wrong input..... ");
}
	return 0;
}
