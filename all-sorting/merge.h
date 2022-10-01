#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
void merge(int *, int *, int , int*, int);


void mergeSort(int *arr, int len){
	if(len == 1)
		return;
	
	int mid = len/2 ;
	int *left = (int*)calloc(mid,sizeof(int));
	memcpy(left,arr,mid*sizeof(int));
	int *right = (int*)calloc(len-mid , sizeof(int));
	memcpy(right,&arr[(int)ceil(len/2)],(len-mid)*sizeof(int));
	mergeSort(left,mid);
	mergeSort(right,len-mid);
	merge(arr,left,mid,right,len-mid);
//	free(left);
//:	free(right);
}

void merge(int * arr , int *left , int left_len , int *right , int  right_len){
	int i = 0 , j = 0 , k = 0 ;
	while(i < left_len && j < right_len){
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
	while(i<left_len){
		arr[k] = left[i];
		i++;
		k++;
	}
	while(j<right_len){
		arr[k] = right[j];
		j++;
		k++;
	}
}
