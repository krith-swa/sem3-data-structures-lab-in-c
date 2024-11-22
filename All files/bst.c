//implementation of binary search tree ADT

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"

int areIdentical(pnodeBST,pnodeBST);
int numLeafNodes(pnodeBST);
int numNonLeafNodes(pnodeBST);
int totalNodes(pnodeBST);

int areIdentical (pnodeBST root1, pnodeBST root2) {
	if (!root1 && !root2)
		return 1;
	if (!root1 || !root2)
		return 0;
	if (root1->key == root2->key)
		return ( areIdentical(root1->left,root2->left) && areIdentical(root1->right,root2->right) );
	return 0;
	}

int numLeafNodes (pnodeBST root) {
	if (!root)
		return 0;
	if (!root->left && !root->right)
		return 1;
	int lTotal = numLeafNodes(root->left);
	int rTotal = numLeafNodes(root->right);
	
	return lTotal+rTotal;
	}
	
int numNonLeafNodes (pnodeBST root) {
	return totalNodes(root)-numLeafNodes(root);
	}

int totalNodes (pnodeBST root) {
	if (!root)
		return 0;
	if (!root->left && !root->right)
		return 1;
		
	int lTotal = totalNodes(root->left);
	int rTotal = totalNodes(root->right);
	
	return lTotal+rTotal+1;
	}

int main() {
	char cmd[20]; int ch=0;
	pnodeBST head[2] = {NULL,NULL};
	
	printf("Enter a command: ");
	scanf("%[^\n]s",cmd);

	//use strtok() to split command into 3 parts - instruction, tree, key
	int t=0; char* token[3];
	token[0] = strtok(cmd," ");
	while (token[t] != NULL)
		token[++t] = strtok(NULL," ");
	
	do {	
		if (strcmp(token[0],"insert")==0) {
			int value = atoi(token[2]);
			int tree = token[1][strlen(token[1])-1]-'0';
			//printf("Tree %d: \n",tree);
			tree--;
			head[tree] = insertNode(head[tree],value);
			//levelorder(head[tree]);
			}
		else if (strcmp(token[0],"delete")==0) {
			int value = atoi(token[2]);
			int tree = token[1][strlen(token[1])-1]-'0';
			printf("Tree %d: \n",tree);
			tree--;
			head[tree] = deleteNode(head[tree],value);
			levelorder(head[tree]);
			}
		else if (strcmp(token[0],"search")==0) {
			int value = atoi(token[2]);
			int tree = token[1][strlen(token[1])-1]-'0';
			printf("Tree %d: \n",tree);
			tree--;	
			pnodeBST temp = search(head[tree],value);
			if (temp)
				printf("%d found!\n\n",temp->key);
			else
				printf("Not found!\n\n");
			}
		else if (strcmp(token[0],"max")==0) {
			int tree = token[1][strlen(token[1])-1]-'0';
			printf("Tree %d: \n",tree);
			tree--;
			pnodeBST temp = maximum(head[tree]);
			printf("Maximum: %d\n\n",temp->key);
			}
		else if (strcmp(token[0],"min")==0) {
			int tree = token[1][strlen(token[1])-1]-'0';
			printf("Tree %d: \n",tree);
			tree--;
			pnodeBST temp = minimum(head[tree]);
			printf("Minimum: %d\n\n",temp->key);
			}
		else if (strcmp(token[0],"inorder")==0) {
			int tree = token[1][strlen(token[1])-1]-'0';
			printf("Tree %d: \n",tree);
			tree--;
			inorder(head[tree]);
			printf("\n\n");
			}
		else if (strcmp(token[0],"preorder")==0) {
			int tree = token[1][strlen(token[1])-1]-'0';
			printf("Tree %d: \n",tree);
			tree--;
			preorder(head[tree]);
			printf("\n\n");
			}
		else if (strcmp(token[0],"postorder")==0) {
			int tree = token[1][strlen(token[1])-1]-'0';
			printf("Tree %d: \n",tree);
			tree--;
			postorder(head[tree]);
			printf("\n\n");
			}
		else if (strcmp(token[0],"levelorder")==0) {
			int tree = token[1][strlen(token[1])-1]-'0';
			printf("Tree %d: \n",tree);
			tree--;
			levelorder(head[tree]);
			}
		else if (strcmp(token[0],"display")==0) {
			int tree = token[1][strlen(token[1])-1]-'0';
			printf("Tree %d: \n",tree);
			tree--;
			levelorder(head[tree]);
			}
		else if (strcmp(token[0],"nodes")==0) {
			int tree = token[1][strlen(token[1])-1]-'0';
			printf("Tree %d: \n",tree);
			tree--;
			printf("Total no. of nodes: %d\n\n",totalNodes(head[tree]));
			}
		else if (strcmp(token[0],"leafnodes")==0) {
			int tree = token[1][strlen(token[1])-1]-'0';
			printf("Tree %d: \n",tree);
			tree--;
			printf("No. of leaf nodes: %d\n\n",numLeafNodes(head[tree]));
			}
		else if (strcmp(token[0],"innodes")==0) {
			int tree = token[1][strlen(token[1])-1]-'0';
			printf("Tree %d: \n",tree);
			tree--;
			printf("No. of non-leaf nodes: %d\n\n",numNonLeafNodes(head[tree]));
			}
		else if (strcmp(token[0],"identical")==0) {
			int tree1 = token[1][strlen(token[1])-1]-'0';
			int tree2 = token[2][strlen(token[2])-1]-'0';
			tree1--;
			tree2--;
			if (areIdentical(head[tree1],head[tree2]))
				printf("IDENTICAL\n\n");
			else
				printf("NOT IDENTICAL\n\n");
			}
		else if (strcmp(token[0],"end")==0) {
			ch=1;
			printf("Exiting the program...\n");
			exit(0);
			}
		else {
			printf("Invalid command!\n");
			exit(0);
			}

		for (int i=0; i<3; i++) {
			if (token[i] != NULL)
				memset(token[i],0,strlen(token[i]));
			}
		
		printf("Enter a command: ");
		scanf(" %[^\n]s",cmd);
		
		t=0;
		token[0] = strtok(cmd," ");
		while (token[t] != NULL)
			token[++t] = strtok(NULL," ");

		} while (ch==0);
	
	return 0;
	}


