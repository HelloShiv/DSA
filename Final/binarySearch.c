#include<stdio.h>
#include<stdlib.h>

int binarySearch(int *arr ,int size,int data){
	int low = 0 ;
	int high = size;
	int mid = (low + high)/2;
	while(low <= high){
		mid = (low + high)/2;
		if(arr[mid] == data)
			return 1;
		else if(arr[mid] < data)
			low = mid +1;
		else if (arr[mid] > data)
			high = mid -1;
	}
	return -1;
}

int main(){
	int arr[] = {11,12,13,14,15,16,17,18};
	int size = sizeof(arr)/sizeof(int);
	int i = binarySearch(arr,size,113);
	printf("Target found: %d ", i );
	return 0;
}
