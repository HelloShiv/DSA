#include<stdio.h>
#include<stdlib.h>

void print(int *arr , int size){
	printf("\n ");
	for(int i = 0 ; i < size;i++)
		printf("%d ", arr[i]);
}

void insertion(int *arr , int size){
	for(int i = 0 ; i < size-1 ; i++){	//because j is initialized with i+1 so it will go out of bound if i < size
		for(int j = i +1 ; j> 0; j--){
			if(arr[j-1]>arr[j]){
				int temp = arr[j-1];
				arr[j-1] = arr[j];
				arr[j] = temp;
			}
			else break;
		}
	}
}

int main(){
	int arr[] = {9,8,7,6,5,4,3,2,1};
	int size = sizeof(arr)/sizeof(int);
	print(arr,size);
	insertion(arr,size);
	print(arr,size);
	return 0;
}
