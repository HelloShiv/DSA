#include<stdio.h>
#include<cstdlib.h>
void printArray(int*,int);
void mergeSort(int*,int,int);

int main(){
	int arr[] = {9,8,7,6,5,4,3,2,1};
	int arr_len = sizeof arr / sizeof arr[0] ; 
	printArray(arr,arr_len);
	mergeSort(arr,0,arr_len-1);
	return 0;
}

int *  mergeSort(int *arr, int low, int high){
	if(sizeof arr / sizeof arr[0] == 1)
		return arr;
	int mid = low + (high -low)/2;
	
	int *left = (int*)malloc((mid-low)*sizeof int);
	int *right = (int*)malloc((high-mid-1)*sizeof int);
	
	for(int i = 0 ; i <= mid;i++)
		left[i] = mergeSort(arr,low,mid);

	for(int i = 0 ; i <= high-mid-1;i++)
                right[i] = mergeSort(arr,mid+1,high);
	
	merge(left, sizeof left / sizeof left[0] , right ,sizeof right / sizeof right[0]);
}

void printArray(int *arr,int arr_len){
	for(int i =0 ; i< arr_len ; i++)
		printf("%d ", arr[i]);
	printf("\n");
}
