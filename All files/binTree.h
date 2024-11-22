//Binary tree ADT structure

#include "BTnode.h"
#include "BTstack.h"
#include "BTqueue.h"

ptnode construct(char*);
void inorder(ptnode);
void preorder(ptnode);
void postorder(ptnode);
void levelorder(ptnode);
void visit(char);
int height(ptnode);

ptnode construct (char* postfix) {
	int size = strlen(postfix);
	btStack_ptr exprStack = createBTStack(size);
	for (int i=0; i<size; i++) {
		char c = postfix[i];
		if (isalnum(c)) {
			pushBT(exprStack,insertNode(c));
			}
		else {
			ptnode head = insertNode(c);
			head->right = popBT(exprStack);
			head->left = popBT(exprStack);
			pushBT(exprStack,head);
			}
		}
	return popBT(exprStack);
	}
	
void inorder (ptnode root) {
	if (root) {
		inorder(root->left);
		visit(root->data);
		inorder(root->right);
		}
	}
	
void preorder (ptnode root) {
	if (root) {
		visit(root->data);
		preorder(root->left);
		preorder(root->right);
		}
	}
	
void postorder (ptnode root) {
	if (root) {
		postorder(root->left);
		postorder(root->right);
		visit(root->data);
		}
	}
	
void levelorder (ptnode root) {
	btQueue_ptr levelQueue = createBTQueue(SIZE);
	ptnode EOL = insertNode('|');
	ptnode EOB = insertNode(';');
	ptnode blank = insertNode('_');
	int ht = height(root);
	
	enqueueBT(levelQueue,EOL);
	int level = 1, k=0, eob=0;
	for (int i=0; i<=(ht-level); i++)
		printf("\t");
	while (root) {
		if (root!=blank && root!=EOB) {
			printf("%c\t\t",root->data);
			if (root->left)
				enqueueBT(levelQueue,root->left);
			else
				enqueueBT(levelQueue,blank);
			if (root->right)
				enqueueBT(levelQueue,root->right);
			else
				enqueueBT(levelQueue,blank);
			enqueueBT(levelQueue,EOB);
			root = dequeueBT(levelQueue);
			}
			
		while (root == blank) {
			root = dequeueBT(levelQueue);
			printf("\t");
			k++;
			}
		while (root == EOB) {
			root = dequeueBT(levelQueue);
			if (root != EOL) {
				printf("  ");
				eob++;
				}
			}
		if (root == EOL) {
			root = dequeueBT(levelQueue);
			if (root != NULL) {
				enqueueBT(levelQueue,EOL);
				level++;
				printf("\n\n");
				for (int i=0; i<=(ht-level); i++)
					printf("\t");
				for (int i=0; i<k; i++)
					printf("\t");
				for (int i=0; i<eob; i++)
					printf("   ");
				}
			}
		}
	printf("\n");
	}
	
void visit (char value) {
	printf("%c",value);
	}
	
int height (ptnode root) {
	if (!root)
		return 0;
	int leftHt = height(root->left);
	int rightHt = height(root->right);
	
	if (leftHt > rightHt)
		return leftHt+1;
	else
		return rightHt+1;
	}

int heightInt (ptnodeInt root) {
	if (!root)
		return 0;
	int leftHt = heightInt(root->left);
	int rightHt = heightInt(root->right);
	
	if (leftHt > rightHt)
		return leftHt+1;
	else
		return rightHt+1;
	}

