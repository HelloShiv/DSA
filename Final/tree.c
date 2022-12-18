#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node *left, *right;
}node;

node* createNode(int data){
	node* new_node = (node*)calloc(1,sizeof(node));
	new_node->data = data;
	new_node->right = new_node->left = NULL;
	return new_node;
}

node* insertNode(node* root,int data){
	if(root == NULL)
		return createNode(data);
	if (root->data < data){
		root->right = insertNode(root->right,data);
	}
	else if(root->data > data){
		root->left = insertNode(root->left,data);
	}
	return root;
}

void inorder(struct node* root)
{
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int  maxOfLeft(node* root ){
	while(root->right!=NULL){
		root = root->right;
	}
		return root->data;
}

node* remove(node* root ,  int data){
	if(root == NULL)
		return root;
	if(root->data < data)
		root->right = remove(root->right,data);
	else if (root->data > data)
		root->left = remove(root->left,data);
	else{
		if(!root->left)
			return root->right;
		else if(!root->right)
			return root->left;
		else
			root->data = maxOfLeft(root->left);
			root->left = remove(root->left,root->data);
	
	} 
	return root;
}


node* inverse(node* root){
	if(root == NULL)
		return root;
	node* l = inverse(root->left);
	node* r = inverse(root->right);
	root->left = r;
	root->right = l;
	return root;
}

int main(){
	
    /* Let us create following BST
              50
           /     \
          30      70
         /  \    /  \
       20   40  60   80 	20,30,40,50,60,70,80	*/

	 struct node* root = NULL;
    root = insertNode(root, 50);
    insertNode(root, 30);
    insertNode(root, 20);
    insertNode(root, 40);
    insertNode(root, 70);
    insertNode(root, 60);
    insertNode(root, 80);
 
    // print inoder traversal of the BST
    inorder(root);
	printf("\n");
//	root = inverse(root);
	/*
			50
		70		30
	     80     60        40    20
	
		80,70,60,50,40,30,20
		

	*/

//	inorder(root);
	root = remove(root,50);
	printf("\n\n");
	inorder(root);

	return 0;
}
