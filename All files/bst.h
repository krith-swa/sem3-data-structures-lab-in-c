//Binary Search Tree ADT structure

#include "bstNode.h"
#include "bstQueue.h"

pnodeBST insertNode(pnodeBST,int);
pnodeBST deleteNode(pnodeBST,int);
void inorder(pnodeBST);
void preorder(pnodeBST);
void postorder(pnodeBST);
void levelorder(pnodeBST);
pnodeBST search(pnodeBST,int);
pnodeBST maximum(pnodeBST);
pnodeBST minimum(pnodeBST);
void visit(int);
int height(pnodeBST);
	
pnodeBST insertNode (pnodeBST root, int key) {
	if (!root)
		return createNode(key);
	if (key <= root->key)
		root->left = insertNode(root->left,key);
	else if (key > root->key)
		root->right = insertNode(root->right,key);
	return root;
	}
	
pnodeBST deleteNode (pnodeBST root, int key) {
	//base case
	if (!root)
		return root;
	
	//find position of key to be deleted
	if (key < root->key)
		root->left = deleteNode(root->left,key);
	else if (key > root->key)
		root->right = deleteNode(root->right,key);
	//node found
	else {
		//node with one child or no children
		if (!root->left) {
			pnodeBST temp = root->right;
			free(root);
			return temp;
			}
		else if (!root->right) {
			pnodeBST temp = root->left;
			free(root);
			return temp;
			}
		//node with two children
		pnodeBST temp = minimum(root->right); //replace root with smallest in right subtree
		root->key = temp->key;
		root->right = deleteNode(root->right,temp->key);
		}
	return root;
	}

void inorder (pnodeBST root) {
	if (root) {
		inorder(root->left);
		visit(root->key);
		inorder(root->right);
		}
	}
	
void preorder (pnodeBST root) {
	if (root) {
		visit(root->key);
		preorder(root->left);
		preorder(root->right);
		}
	}
	
void postorder (pnodeBST root) {
	if (root) {
		postorder(root->left);
		postorder(root->right);
		visit(root->key);
		}
	}
	
void levelorder (pnodeBST root) {
	bstQueue_ptr levelQueue = createBSTQueue(SIZE);
	pnodeBST EOL = createNode('|');
	pnodeBST EOB = createNode(';');
	pnodeBST blank = createNode('_');
	int ht = height(root);
	
	enqueueBST(levelQueue,EOL);
	int level = 1, k=0, eob=0;
	for (int i=0; i<=(ht-level); i++)
		printf("\t");
	while (root) {
		if (root!=blank && root!=EOB) {
			printf("%d\t\t",root->key);
			if (root->left)
				enqueueBST(levelQueue,root->left);
			else
				enqueueBST(levelQueue,blank);
			if (root->right)
				enqueueBST(levelQueue,root->right);
			else
				enqueueBST(levelQueue,blank);
			enqueueBST(levelQueue,EOB);
			root = dequeueBST(levelQueue);
			}
			
		while (root == blank) {
			root = dequeueBST(levelQueue);
			printf("\t");
			k++;
			}
		while (root == EOB) {
			root = dequeueBST(levelQueue);
			if (root != EOL) {
				printf("  ");
				eob++;
				}
			}
		if (root == EOL) {
			root = dequeueBST(levelQueue);
			if (root != NULL) {
				enqueueBST(levelQueue,EOL);
				level++;
				printf("\n\n");
				for (int i=0; i<=(ht-level); i++)
					printf("\t");
				for (int i=0; i<k; i++)
					printf("  ");
				for (int i=0; i<eob; i++)
					printf(" ");
				}
			}
		}
	printf("\n");
	}

pnodeBST search (pnodeBST root, int key) {
	if (!root || root->key == key)
		return root;
	if (root->key < key)
		return search(root->right,key);
	return search(root->left,key);
	}
	
pnodeBST maximum (pnodeBST root) {
	pnodeBST current = root;
	while (current && current->right)
		current = current->right;
	return current;	
	}
	
pnodeBST minimum (pnodeBST root) {
	pnodeBST current = root;
	while (current && current->left)
		current = current->left;
	return current;
	}
	
void visit (int value) {
	printf("%d ",value);
	}
	
int height (pnodeBST root) {
	if (!root)
		return 0;
	int leftHt = height(root->left);
	int rightHt = height(root->right);
	
	if (leftHt > rightHt)
		return leftHt+1;
	else
		return rightHt+1;
	}


