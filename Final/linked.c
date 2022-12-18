#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node *next;
}node;
node* head = NULL;

node* newNode(int data){
	node* new_node = (node*)calloc(1,sizeof(node));
	new_node->data = data;
	new_node->next = NULL;
	return new_node;
}

node* lastNode(){
	node* temp = head;
	while(temp->next!=NULL)
		temp = temp->next;
	return temp;
}
void  create(int data){
	if(!head){
		head = newNode(data);
		return;
	}
	else{
		node* lptr = lastNode();
		lptr->next = newNode(data);
	}
}

void delete_start(){
	node * temp = head;
	head = head->next;
	free(temp);
	return;
}

void delete_end(){
	node* temp = head ,*preptr;
	while(temp->next!=NULL){
		preptr = temp;
		temp = temp->next;
	}
	preptr->next = NULL;
	free(temp);
}

void delete_at(int data){
	node* temp = head , *preptr;
	if(temp->data == data)
		delete_start();
	else if (lastNode()->data == data)
		delete_end();
	else{
	while(temp->data != data && temp != NULL){
		preptr = temp;
		temp = temp->next;
	}
	if(temp->data == data){
		preptr->next = temp->next;
		free(temp);
	}
	}
}

void insert_beg(int data){
	node* new_node = newNode(data);
	new_node->next = head;
	head = new_node;
}

void insert_end(int data){
	node* lptr = lastNode();
	lptr->next = newNode(data);
	lptr->next->next = NULL;
}
node* find(int data){
	node* temp = head;
	while(temp->data != data){
			temp = temp->next;
		if(temp->next == NULL)
			return newNode(-1);
	}
	return temp;
}

void insert_after(int lock , int key){
	if(find(lock)->data){
		node* temp = head, *postptr;
	if(lastNode()->data == lock)
		insert_end(key);
	else{	
	// printf("\nI AM HERE");
		node* target = find(lock);
		printf("\n\n %d target value: ", target->data);
		if(find(lock)->next)
			postptr = target->next;
		target->next = newNode(key);
		target->next->next = postptr;		
	}
	}
}


void print(){
	node* temp = head;
	printf("\n");
	while(temp){
		printf(" %d -> ", temp->data);
		temp = temp->next;
	}
}

int main(){
	for(int i = 0 ; i < 10 ; i ++)
		create(i);
	print();
	delete_start();delete_start();
	print();

	delete_end();delete_end();
	print();
	delete_at(6);delete_at(5);
	print();
	insert_beg(1);insert_beg(0);
	insert_end(8);insert_end(9);
	print();
	insert_after(9,10);insert_after(4,5);insert_after(5,6);insert_after(0,11);
	// printf("\n\n %d target aquired: ", find(11)->data);
	print();
	return 0;
}