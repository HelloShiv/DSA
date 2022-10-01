#include<stdio.h>
void sort(int *,int);
int getMaxIndex(int *,int,int);
void print(int*,int);
void swap(int*,int,int);
void sort(int *arr ,int arrc ){
	for(int i =0 ; i<arrc ; i++){
		int last = arrc - i -1;
		int maxIndex = getMaxIndex(arr,0,last);
		swap(arr,maxIndex,last);
	} 
	print(arr,arrc);
}

int getMaxIndex(int *arr , int start , int end){
	int max = start;
	for(int i = start; i < end ; i++){
		if(arr[max]<arr[i]){
			max = i;
		}
	}	
	return max;
}

void swap(int *arr, int first, int last){
	int temp = arr[first];
	arr[first] = arr[last];
	arr[last] = temp;
}

void print(int *arr, int arrc){
	for(int i=0; i <arrc;i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}
