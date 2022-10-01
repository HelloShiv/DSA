#include<stdio.h>
#include<stdlib.h>
void print(int*,int);
void quickSort(int *arr,int start,int end);
int main(){
	int arr[] = {12,13,6,5,4,32,1,0,8,9};
	int len = sizeof(arr)/sizeof(arr[0]);
	print(arr,len);
	quickSort(arr,0,len-1);
	print(arr,len);
	return 0;
}
void quickSort(int *arr,int start,int end){
	int i , j  , pivot , temp;
	if(start<end){
		pivot = start;
		i = start ;
		j = end ;
	
	while(i<j){
		while(arr[i]<=arr[pivot]&&i<end)
			i++;
		while(arr[j]>arr[pivot])
			j--;
		if(i<j){
			temp = arr[i];
			arr[i] = arr[j];	
			arr[j] = temp;
		}
	}
		temp = arr[pivot];
		arr[pivot] = arr[j];
		arr[j] = temp;
		quickSort(arr,start,j-1);
		quickSort(arr,j+1,end);
		
   }
}

void print(int *arr,int len){
	for(int i = 0 ; i < len ; i++)
		printf("%d ", arr[i]);
	printf("\n");
}
