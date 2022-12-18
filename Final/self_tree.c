#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node *left , *right;
}node;
//node *root = NULL;

node* newNode(int data){
	node* new_node = (node*)calloc(1,sizeof(node));
	new_node->data = data;
	new_node->left = NULL;
	new_node->right = NULL;
	return new_node;
}

node* create(node* r,int data){
	if(r == NULL){
		r = newNode(data);
		return r;
	}
	else if(r->data < data)
		r->right = create(r->right,data);
	else
		r->left = create(r->left, data);
	return r;
}

int maxOfLeft(node* root){
	while(root->right != NULL)
		root = root->right;
	return root->data;
}

node* remove(node* root,int data){
	if(root == NULL)
		return root;
	if(root->data <data)
		root->right = remove(root->right,data);
	else if(root->data > data)
		root->left = remove(root->left,data);
	else{
		if(!root->left)
			return root->right;
		else if(!root->right)
			return root->left;	
		else{
			root->data = maxOfLeft(root);
			root->left = remove(root->left , root->data);
		}
	}
	return root;
}

void inorder(node *root){
	if(root == NULL)
		return ;
	inorder(root->left);
	printf("%d ,", root->data);
	inorder(root->right);
}


int main(){
	node* root = NULL;
	for(int i = 0 ; i < 10 ; i++)
		root = create(root,32-i);
	
	inorder(root);
	int j = 5;
	root = remove(root,30);
	while(j){
	printf("\n");
	root =remove(root,29-j);
	inorder(root);
	j--;
	}
	return 0;
}
