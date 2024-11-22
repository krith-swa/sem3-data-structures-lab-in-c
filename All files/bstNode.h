//BST node structure

struct bst {
	int key;
	struct bst* left;
	struct bst* right;
	};
	
typedef struct bst* pnodeBST;

pnodeBST createNode(int);

pnodeBST createNode (int value) {
	pnodeBST newNode = (pnodeBST) malloc(sizeof(struct bst));
	if (!newNode)
		return NULL; //memory error
	newNode->key = value;
	newNode->left = NULL;
	newNode->right = NULL;
	
	return newNode;
	}

