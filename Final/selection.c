#include<stdio.h>
#include<stdlib.h>
void print(int* arr, int size){
	printf("\n");
	for(int i = 0 ; i < size ; i ++)
		printf("%d ,", arr[i]);
}
int getMinIndex(int*,int,int);
void sort(int * , int);
void swap(int*,int,int);
int main(){
	int arr[] = {8,6,3,5,6,3,2,15,6,7};
	int size = sizeof(arr)/sizeof(int);
	print(arr,size);
	sort(arr,size);
	print(arr,size);
	return 0;
}

void sort(int *arr , int size){
	for(int i = 0 ; i < size ; i ++){
		int minIndex = getMinIndex(arr,i,size);
		swap(arr,i,minIndex);
	}

}

int getMinIndex(int *arr ,int start , int end){
	int small = start;
	for(int i = start ; i < end ; i++){
		if(arr[small] >arr[i])
			small = i;
	}
	return small;
}

void swap (int* arr, int first , int second){
	int temp = arr[first];
	arr[first] = arr[second];
	arr[second] = temp;
}
