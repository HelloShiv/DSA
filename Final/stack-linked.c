#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node *next;
}node;
node* top = NULL;

node* newNode(int data){
	node* new_node = (node*)calloc(1,sizeof(node));
	new_node->data = data;
	new_node->next = NULL;
	return new_node;
}

void createNode(int data){
	if(!top)
		top = newNode(data);
	else{
		node* new_node = newNode(data);
		new_node->next = top;
		top = new_node;
	}
}

void pop(){
	if(!top)
		printf("\n STACK UNDERFLOW");
	else{	node *temp = top;
		printf("%d ->, ", top->data);
		top = top->next;
	}
}

void display(){
	node *temp = top;
	printf("\n");
	while(temp){
		printf(" %d <=>", temp->data);
		temp = temp->next;
	}
}

int main(){
	for(int i = 0 ; i < 10 ; i++)
		createNode(i);
	display();
	printf("\n");pop();
	display();	
	return 0;
}
