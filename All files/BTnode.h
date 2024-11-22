//binary tree node structure

struct tnode {
	char data;
	struct tnode* left;
	struct tnode* right;
	};

struct tnodeInt {
	int data;
	char item;
	struct tnodeInt* left;
	struct tnodeInt* right;
	};
	
typedef struct tnode* ptnode;
typedef struct tnodeInt* ptnodeInt;

ptnode insertNode(char);
ptnodeInt insertNodeInt(int);

ptnode insertNode (char value) {
	ptnode newNode = (ptnode) malloc(sizeof(struct tnode));
	if (!newNode)
		return NULL; //memory error
	newNode->data = value;
	newNode->left = NULL;
	newNode->right = NULL;
	
	return newNode;
	}
	
ptnodeInt insertNodeInt(int value) {
	ptnodeInt newNode = (ptnodeInt) malloc(sizeof(struct tnodeInt));
	if (!newNode)
		return NULL; //memory error
	newNode->data = value;
	newNode->item = '$';
	newNode->left = NULL;
	newNode->right = NULL;
	
	return newNode;
	}
	
ptnodeInt insertNodeChar(char value) {
	ptnodeInt newNode = (ptnodeInt) malloc(sizeof(struct tnodeInt));
	if (!newNode)
		return NULL; //memory error
	newNode->data = 0;
	newNode->item = value;
	newNode->left = NULL;
	newNode->right = NULL;
	
	return newNode;
	}

