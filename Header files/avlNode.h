//AVL node structure

#define MAX 50

struct AVLNode {
	char data[MAX];
	struct AVLNode *left;
	struct AVLNode *right;
	int height;
	};	
typedef struct AVLNode* AVL;

AVL createNode(char[]);

AVL createNode (char item[]) {
	AVL newNode = (AVL) malloc(sizeof(struct AVLNode));
	if (!newNode)
		return NULL; //memory error
	strcpy(newNode->data,item);
	newNode->left = NULL;
	newNode->right = NULL;
	newNode->height = 1;
	
	return newNode;
	}

