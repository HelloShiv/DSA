#include<stdio.h>
#include<stdlib.h>
int main(){
        int n,item;
        printf("Enter number of arrays to be inserted: ");
        scanf("%d" , &n);
        int *arr = (int*)malloc(n*sizeof(int));
        printf("Enter elements of array: ");
        for(int i =0 ; i<n ; i++)
                scanf("%d",arr+i);
        printf("Enter item to be searched: ");
        scanf("%d" , &item);
	int low = 0; int high = n;       
	while(low<=high){
                int mid = low + (high -low)/2;
                if(arr[mid] == item){
                        printf("Element Found");
			return 0;
		}
                else if (arr[mid] < item)
                        low = mid + 1;
                else
                        high = mid -1;
        }
        printf("Not Found"); free(arr);


        return 0;
}
