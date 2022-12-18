#include<stdio.h>
#include<stdlib.h>
void quickSort(int*,int,int);
void print(int* arr , int size){
	printf("\n");
	for(int i = 0 ; i < size ; i++)
		printf("%d ,", arr[i]);
}

int main(){
	int arr[] = { 8,6,5,2,5,7,3,2,135,5};
	int size = sizeof(arr)/sizeof(int);
	print(arr,size);
	quickSort(arr,0,size-1);
	print(arr,size); 
	return 0;
}

void quickSort(int *arr, int low , int high){
	if(low > high)		//how will it come out of recurrsion
		return ;	
	int start = low;
	int end = high;
	int pivot = (low+high)/2;
	while(start<=end){
		while(arr[start]<arr[pivot]){
			start++;
		}
		while(arr[end] > arr[pivot]){
			end--;
		}
		if(start<=end){
			int temp = arr[start];
			arr[start] = arr[end];
			arr[end] = temp;
			start++;end--;
		}
	}
	quickSort(arr,low,end);
	quickSort(arr,start,high);

}
