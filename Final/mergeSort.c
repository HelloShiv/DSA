#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
void mergeSort(int * , int);
void merge(int*,int*,int,int*,int);
void print(int *arr, int size){
	printf("\n");
	for(int i = 0 ; i < size ; i++)
		printf("%d , ", arr[i]);

}
int main(){
	int arr[] = {9,7,5,3,4,6,8,9,3,2,1};
	int size = sizeof(arr)/sizeof(int);
	print(arr,size);
	mergeSort(arr,size);
	print(arr,size);
	return 0;
}

void mergeSort(int *arr ,int size){
	if(size == 1 || size == 0)
		return;
	int *left = (int*)calloc(size/2,sizeof(arr));
	memcpy(left,arr,(size/2)*sizeof(int));
	int *right = (int*)calloc(size-(size/2),sizeof(int));
	memcpy(right,&arr[(int)ceil(size/2)],(size-size/2)*sizeof(int));
	mergeSort(left,size/2);
	mergeSort(right,(size-size/2));
	merge(arr,left,size/2,right,size-size/2);
}	

void merge(int *arr,int *left , int lsize,int *right,int rsize){
	int *mix = (int*)calloc(lsize+rsize,sizeof(int));
	int i=0,j=0,k=0;
	while(i<lsize && j < rsize){
		if(left[i]<right[j]){
			arr[k] = left[i];
			i++;
		}
		else{
			arr[k] = right[j];
			j++;
		}
		k++;
	}
	while(i<lsize){
		arr[k] = left[i];
		i++;
		k++;
	}
	while(j<rsize){
		arr[k] = right[j];
		j++;
		k++;
	}
		
}
