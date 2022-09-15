#include<stdio.h>
#include<stdlib.h>

int main(){
	int n,item;
	printf("Enter number of arrays to be inserted: ");	
	scanf("%d" , &n);
	int *arr = (int*)malloc(n*sizeof(int));
	printf("Enter elements of array: ");
	for(int i =0 ; i<n ; i++)
		scanf("%d",arr+i);
	printf("Enter item to be searched: ");
	scanf("%d" , &item);	
	
	for(int j =0 ; j<n;j++){
		if(arr[j] == item){
				printf("Item found");
				return 0;
			}
			
	}
	printf("Element not found");
	
	return 0;
}
