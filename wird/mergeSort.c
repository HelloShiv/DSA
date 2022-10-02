#include<stdio.h>
#include<stdlib.h>
int * merge(int * first ,int first_len, int * second, int second_len);
int * mergeSort(int *arr, int low , int high);

int * mergeSort(int *arr, int low , int high){
	if(sizeof(arr)/sizeof(arr[0]) == 1)
		return arr;
	
	int mid = high + (low - high)/2;
	int n1 = mid- low ;
	int n2 = high - mid+1;
	int left[n1]; // =  mergeSort(arr,low , mid );	
	int right[n2]; // = mergeSort(arr,mid+1,high);
	
	for(int i=0;i<n1;i++)	left[i] = arr[i];
	for(int j=0;j<n2;j++)	right[j] = arr[mid+j];	


	return merge(left,sizeof(left)/sizeof(left[0]), right , sizeof(right)/sizeof(right[0]));
}

int * merge(int * first ,int first_len, int * second, int second_len){
	int *mix = (int*)malloc((first_len+second_len)*sizeof(int));
	int i =0 , j= 0 , k =0;
	while(i<first_len && j <second_len){
		if(first[i] <= second[j]){
			mix[k] = first[i];
			i++;
		}
		else{
			mix[k] = second[j];
			j++;
		}
		k++;
	}

	while(i < first_len){
		mix[k] = first[i];
		k++;
		i++;
	}
	
	while(j < second_len){
		mix[k] = second[j];
		k++;
		j++;
	}
	
	return	mix;
}

int main(){
	int arr[] = {12,11,13,5,6,7,67,55,33,43};
	int arr_len = sizeof(arr)/sizeof(arr[0]);
	for(int i =0 ; i < arr_len; i++)
                      printf("%d ", *(arr + i));	
	printf("\n");
	int *modified  = mergeSort(arr,0,arr_len);
		for(int i =0 ; i < arr_len; i++)
			printf("%d ", *(modified + i));
	return 0;
}
