#include<stdio.h>
#include<stdlib.h>


typedef struct node{
	
	int data;
	struct node* left;
	struct node* right;
}sn;

sn* createNode(int data){
	
	sn* newnode;
	newnode=(sn*)malloc(sizeof(sn));
	
	if(newnode==NULL)
		printf("memory not allocated");
	
	newnode->data =data;
	newnode->left =NULL;
	newnode->right =NULL;
	
	
	return newnode;
}

sn* insertNode (sn *root, int data){
	sn *temp;
	if(root == NULL){
		temp = createNode(data);
		return temp;
	}
	else if(data < root->data){
		root->left=insertNode(root->left,data);
	}
	else if(data > root->data ) {
		
		root->right=insertNode(root->right,data);
	}
	
	
	return root;
	
}

int search (sn* root, int target){
	
	if(root==NULL){
		return 0;
	}

	
	if(target==root->data){
		printf("got the element  Hurrayh!!!");
		return 1;
	}
	else if(target<root->data){
		
		return search(root->left,target);
	}
	else if(target > root->data){
		
		return search(root->right,target);
	}

	
	
	
}
int main() {
    sn* root = NULL;  // Start with an empty BST

    // Insert nodes into the BST
    root = insertNode(root, 50);
    root = insertNode(root, 30);
    root = insertNode(root, 20);
    root = insertNode(root, 40);
    root = insertNode(root, 70);
    root = insertNode(root, 60);
    root = insertNode(root, 80);

    
    // Search for a value
    int value = 90;
    if (search(root, value)) {
        printf("Node with value %d found in the BST.\n", value);
    } else {
        printf("Node with value %d not found in the BST.\n", value);
    }

    return 0;
}
