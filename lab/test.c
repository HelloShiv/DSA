#include<stdio.h>
#include<cstring>
#include<stdlib.h>
int main(){
	int arr[] = {11,12,13,414,14,15,16,14,62};
	int arr_len = sizeof(arr)/sizeof(arr[0]);
	int *p = (int*)malloc((arr_len/2)*sizeof(int));
	int *right = (int*)malloc((arr_len-arr_len/2)*sizeof(int));
	
	memcpy(p,arr,(arr_len/2)*sizeof(int));
	for(int i =0 ; i < arr_len/2 ; i++)
		printf("%d ", p[i]);
	memcpy(right,&arr[arr_len - arr_len/2],(arr_len - arr_len/2)*sizeof(int));
	printf("\n");
	for(int i =0 ; i < arr_len - arr_len/2 ; i++)
                  printf("%d ", right[i]);
	return 0;
}
