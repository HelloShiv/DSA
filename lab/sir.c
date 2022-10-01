#include<stdio.h>
void selection(int * , int);
void print(int*,int);
int  getLowestIndex(int*,int,int);
void swap(int*,int,int);
int main(){
	int arr[] = {9,8,7,6,5,4,32,1};
	int arr_len = sizeof(arr)/sizeof(arr_len);
	print(arr,arr_len);
	selection(arr,arr_len);
	return 0;
}

void selection(int *arr,int arr_len){
	for(int i = 0; i <arr_len ; i++){
		int start_index = 0 + i ;
		int low_index = getLowestIndex(arr,0+i,arr_len);
		swap(arr, start_index , low_index);
	}
	print(arr,arr_len);
}

int  getLowestIndex(int * arr ,int low , int high){
	int max = low;
	
	for(int i = low ; i<high ; i++){
		if(arr[max] > arr[i])
			max=i;
	}
	return max;		
}

void swap(int *arr,int first ,int second){
	int temp = arr[first];
	arr[first] = arr[second];
	arr[second] = temp;
}

void print(int *arr, int arrc){
        for(int i=0; i <arrc;i++){
                printf("%d ", arr[i]);
        }
        printf("\n");
}
