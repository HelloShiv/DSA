#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node *next, *prev;
}node;
node* head = NULL;
node* newNode(int data){
	node* new_node = (node*)calloc(1,sizeof(node));
	new_node->data = data;
	new_node->next = NULL;
	new_node->prev = NULL;
	return new_node;
}

node* lastNode(){
	node* temp = head;
	while(temp->next){
		temp = temp->next;
	}
	return temp;
}

void create(int data){
	if(!head){
		head = newNode(data);
		return;
	}else{
		node* lptr = lastNode();
		lptr->next = newNode(data);
		lptr->next->prev = lptr;
	}
}

void print(){
	node* temp = head;
	printf("\n");
	while(temp->next!= NULL){
		printf("%d ", temp->data);
		temp = temp->next;
	}
}

void insert_start(int data){
	node *new_node =  newNode(data);
	new_node->next = head;
	head->prev = new_node;
	head = new_node;
}

void insert_end(int data){
	node *new_node = newNode(data);
	node *lptr = lastNode();
	lptr->next = new_node;
	new_node->prev = lptr;
}

void delete_start(){
	node* temp = head;
	head = head->next;
	head->prev = NULL;
	free(temp);
}


void delete_end(){
	node* lptr = lastNode();
	node *postptr = lptr->prev;
	postptr->next = NULL;
	free(lptr);
}

int main(){
	for(int i = 0 ; i < 10 ; i ++)
		create(i);
	print();
	insert_start(-1);insert_start(-2);
	print();
	insert_end(10);insert_end(11);
	print();
	delete_start();delete_start();delete_end();delete_end();
	print();
	return 0;
}
