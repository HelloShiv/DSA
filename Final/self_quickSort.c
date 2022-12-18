#include<stdio.h>
#include<stdlib.h>
void quicksort(int*,int,int);
void print(int* arr, int size){
	printf("\n");
	for(int i = 0 ; i < size ; i++)
		printf("%d ", arr[i]);
}

int main(){
	int arr[] = {9,84,24,6,5,6,2,56,7,3,1};
	int size = sizeof(arr)/sizeof(int);
	print(arr,size);
	quicksort(arr,0,size-1);
	print(arr,size);
}

void quicksort(int *arr , int low , int high){
	if(low > high)
		return;
	int s = low;
	int e = high;
	int mid = (low+high)/2;
	int pivot = arr[mid];
	
	while(s<=e){
		while(arr[s]<pivot)
			s++;
		while(arr[e]>pivot)
			e--;
		if(s<=e){
			int temp = arr[s];
			arr[s] = arr[e];
			arr[e] = temp;
			s++;e--;
		}
	}
	quicksort(arr,low,e);
	quicksort(arr,s,high);
	
}
