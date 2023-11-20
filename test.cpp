#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node*left;
	struct node*right;
};

struct node* create(int data) {
	struct node *newnode =  (struct node*)malloc(sizeof(struct node));
	newnode->data = data;
	newnode->left = NULL;
	newnode->right = NULL;
	return newnode;
}

struct node* insert(struct node *root, int data) {
	if (root == NULL) {
		return create(data);
	}
	if (data < root->data) {
		root->left = insert(root->left, data);
	} else if (data > root->data) {
		root->right = insert(root->right, data);
	}
	return root;
}

void traverse(struct node * root) {
	if (root == NULL) {
		return ;
	}
	traverse(root->left);
	printf("%d ", root->data);
	traverse(root->right);
}

int main() {
	struct node* root = NULL;
	root = insert(root, 1);
	insert(root, 2);
	insert(root, 3);
	insert(root, 4);
	insert(root, 5);
	traverse(root);
}