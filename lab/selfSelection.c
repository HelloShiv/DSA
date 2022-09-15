#include<stdio.h>
void selection(int *,int);
void swap(int *,int,int);
int getValue(int*,int,int);
void print(int *arr,int len){for(int i=0;i<len;i++)printf("%d ",arr[i]); printf("\n");}
int main(){
	int arr[] = {12,34,89 ,8,7,3,4,2,1};
	int arr_len = sizeof(arr)/sizeof(arr[0]);
	print(arr,arr_len);
	selection(arr,arr_len);
	return 0;
}

void selection(int* arr,int arr_len){
	for(int i =0 ; i < arr_len ; i++){
		int low = i;
		int getLowValue = getValue(arr,low,arr_len);
		swap(arr,low,getLowValue);
	}
	print(arr,arr_len);
}

int getValue(int *arr,int low , int high){
	int min = low;
	for(int i =low ; i <high ; i++){
		if(arr[min]>arr[i])
			min = i; 
	}
	return min;
}

void swap(int *arr,int first,int second){
	int temp = arr[first];	
	arr[first] = arr[second];
	arr[second] = temp;
}
