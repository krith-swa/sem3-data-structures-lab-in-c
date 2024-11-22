//AVL tree - ADT Structure

#include "avlNode.h"
#include "avlQueue.h"

AVL leftRotate (AVL);
AVL rightRotate (AVL);
AVL insert (AVL,char*);
int search (AVL,char*);
void inorder (AVL);
void levelorder (AVL);
void printEntry (char[]);
int height (AVL);
int max (int,int);

//rotate left
AVL leftRotate (AVL avl1) {
	AVL avl2 = avl1->right;
	avl1->right = avl2->left;
	avl2->left = avl1;

	avl1->height = max(height(avl1->left),height(avl1->right))+1;
	avl2->height = max(height(avl2->left),avl1->height)+1;

	return avl2;
	}

//rotate right
AVL rightRotate (AVL avl1) {
	AVL avl2=avl1->left;
	avl1->left=avl2->right;
	avl2->right=avl1;

	avl1->height=max(height(avl1->left), height(avl1->right))+1;
	avl2->height=max(height(avl2->left), avl1->height)+1;

	return avl2;
	}

AVL insert (AVL avl, char item[]) {	
	if (avl==NULL){
		avl = (AVL) malloc(sizeof(struct AVLNode));
		strcpy(avl->data,item);
		avl->left = avl->right = NULL;
		avl->height = 1;
		return avl;
		}
  	if (strcmp(item,avl->data)==0)
		return avl;
	else if (strcmp(item,avl->data)<0) {
		avl->left = insert(avl->left,item);
		if (height(avl->left)-height(avl->right)==2) {
	      		if (strcmp(item,avl->left->data)<0)
				avl = rightRotate(avl);
			else {
				avl->left = leftRotate(avl->left);
				return rightRotate(avl);
				}
			}
		}
	else if (strcmp(item,avl->data)>0) {
		avl->right = insert(avl->right,item);
		if (height(avl->right)-height(avl->left)==2) {
			if (strcmp(item,avl->right->data)>0)
				avl = leftRotate(avl);
			else {
				avl->right = rightRotate(avl->right);
				return leftRotate(avl);
				}
			}
		}
	avl->height = max(height(avl->left),height(avl->right))+1;
	return avl;
	}

int search (AVL avl, char item[]) {
	if (avl) {
		char entry[50], name[50], phone[50];
		char* itemName = strtok(item," ");
		strcpy(entry,avl->data);
		strcpy(name,strtok(entry,"-"));
		strcpy(phone,strtok(NULL," "));
		
		//to search by name
		if ((strcmp(itemName,name)==0)) {
			printEntry(avl->data);
			return 1;
			}
		else if (strcmp(itemName,name)<0)
      			return search(avl->left,item);
    		else
			return search(avl->right,item);
		
		}
	return 0;
	}

void inorder (AVL avl) {
	if (avl) {
		inorder(avl->left);
		printf("%s\n",avl->data);
		inorder(avl->right);
		}
	return;
	}

void levelorder (AVL root) {
	avlQueue_ptr levelQueue = createAVLQueue(SIZE);
	AVL EOL = createNode("|");
	AVL EOB = createNode(";");
	AVL blank = createNode("_");
	int ht = height(root);
	
	enqueueAVL(levelQueue,EOL);
	int level = 1, k=0, eob=0;
	for (int i=0; i<=(ht-level); i++)
		printf("\t");
	while (root) {
		if (root!=blank && root!=EOB) {
			printf("%s\t\t",root->data);
			if (root->left)
				enqueueAVL(levelQueue,root->left);
			else
				enqueueAVL(levelQueue,blank);
			if (root->right)
				enqueueAVL(levelQueue,root->right);
			else
				enqueueAVL(levelQueue,blank);
			enqueueAVL(levelQueue,EOB);
			root = dequeueAVL(levelQueue);
			}
			
		while (root == blank) {
			root = dequeueAVL(levelQueue);
			printf("\t");
			k++;
			}
		while (root == EOB) {
			root = dequeueAVL(levelQueue);
			if (root != EOL) {
				printf("  ");
				eob++;
				}
			}
		if (root == EOL) {
			root = dequeueAVL(levelQueue);
			if (root != NULL) {
				enqueueAVL(levelQueue,EOL);
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

int height (AVL avl) {
	if (avl==NULL)
		return 0;
	return avl->height;
	}

int max (int a, int b) {
	if (a>b)
		return a;
	return b;
	}
	
void printEntry (char text[]) {
	printf("Entry: %s\n",text);
	}

