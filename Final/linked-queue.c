#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node *next;
}node;
node *front = NULL;
node *rear = NULL;

node* newNode(int data){
	node* new_node = (node*)calloc(1,sizeof(node));
	new_node->data= data;
	new_node->next = NULL;
	return new_node;
}

void enqueue(int data){
	if(!front){
		front = newNode(data);
		rear = front;
		rear->next = NULL;
	}else{
		rear->next = newNode(data);
		rear = rear->next;
		rear->next = NULL;
	}
}

void dequeue(){
	node* temp = front;
	if(!temp)
		printf("Underflow");
	else{
		node *deleted = front;
		front =front->next;
		free(deleted);
	}
}
 

void display(node* temp){
	printf("\n");
	if(!temp)
		printf("Underflow");
	else{
		while(temp){
			printf("%d => ", temp->data);
			temp = temp->next;
		}		
	}
	
}

int main(){

	for(int i = 0 ; i < 5 ; i++)
		enqueue(i);
	display(front);
	dequeue();dequeue();
	display(front);
	return 0;
}
