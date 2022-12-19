#include<stdio.h>
#include<stdlib.h>
int front = -1;
int rear = -1;

void enqueue(int *arr ,int data,int n){
	if(front == -1){
		front++;
		rear++;
		arr[rear] = data;
	}
	else if(rear == n-1)
		return;
	else{
		rear++;
		arr[rear] = data;
	}
}

void print(int* arr, int size){
	if(front == -1)	return;
	for(int i = front ; i <size ; i++)
		printf(" %d  ," ,arr[i]);
}

void pop(int* arr){
	if(front == -1 || rear == -1)
		return;
	else{
		printf("\n\n %d DATA POPED", arr[front]);
		front++;
	}
}

int main(){
	int n;
	printf("Enter size : ");scanf(" %d",&n);
	int *arr = (int*)calloc(n,sizeof(int));
	for(int i = 0 ; i < n ; i++)
		enqueue(arr,i,n);
	print(arr,n);
	pop(arr);pop(arr);
	print(arr,n);
	for(int i = 0 ; i < n ; i++)
		pop(arr);
	print(arr,n);
	return 0;
}
