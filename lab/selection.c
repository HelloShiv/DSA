#include<stdio.h>
void selection(int * arr ,int );
int getMaxIndex(int*,int,int);
void swap(int *,int,int);
void print(int*,int);
int main(){
	int arr[] = { 11,9,8,7,6,5,4,3,2,1};
	int arr_len = sizeof(arr)/sizeof(arr[0]);
	print(arr,arr_len);
	selection(arr,arr_len);
	print(arr,arr_len);
	return 0;
}

void selection(int * arr , int arr_len){
	for(int i = 0 ; i<arr_len ; i++){
		int last_index = arr_len -i -1;
		int maxIndex = getMaxIndex(arr,0,last_index);
		swap(arr,maxIndex,last_index);
	}
	
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

void swap(int *arr,int first , int last){
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
