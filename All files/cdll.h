//Circular doubly linked list ADT structure

#define EMPTY 0

typedef struct node {
	int data;
	char label;
	struct node* right;
	struct node* left;
	} cdll_node;

typedef struct node* cdll_ptr;

void insertLast (cdll_ptr*,int,char);
int deleteNode (cdll_ptr*,char);

void insertLast (cdll_ptr* CDLL, int item, char holder) {
	//enter data into new node
	cdll_ptr newNode = (cdll_ptr) malloc(sizeof(cdll_node));
	if (!newNode)
		return; //memory error
	newNode->data = item;
	newNode->label = holder;
	//if empty list, make new node the first/last node (CDLL)
	if (*CDLL == NULL) {
		*CDLL = newNode;
		(*CDLL)->right = *CDLL;
		(*CDLL)->left = *CDLL;
		return;
		}
	//add new node to end of CDLL
	newNode->right = (*CDLL)->right;
	(*CDLL)->right = newNode;
	newNode->left = *CDLL;
	(newNode->right)->left = newNode;
	*CDLL = newNode;
	}
	
int deleteNode (cdll_ptr* CDLL, char holder) {
	//if empty list
	if (!(*CDLL))
		return EMPTY;
	cdll_ptr temp = *CDLL, prev = (*CDLL)->left;
	//if single element list and label is holder, delete that node
	if (((*CDLL)->right == *CDLL) && (temp->label == holder)) {
		*CDLL = NULL;
		int item = temp->data;
		free(temp);
		//return deleted data
		return item;
		}
	//traverse list to find node with holder's label
	do {
		prev = prev->right;
		temp = temp->right;
		} while ((temp != *CDLL) && (temp->label != holder));
	//connect prev node to following node and delete current node
	if (temp->label == holder) {
		int item = temp->data;
		if (temp == *CDLL)
			*CDLL = prev;
		cdll_ptr next = temp->right;
		prev->right = next;
		next->left = prev;
		free(temp);
		//return deleted data
		return item;
		}
	//if holder not found
	return -1;
	}
	
int size (cdll_ptr CDLL) {
	int count = 0;
	if (!CDLL)
		return count;
	cdll_ptr temp = CDLL;
	do {
		count++;
		temp = temp->right;
		} while (temp != CDLL);
	return count;
	}
	
cdll_ptr search (cdll_ptr CDLL, char holder) {
	if (!CDLL)
		return NULL;
	cdll_ptr temp = CDLL;
	do {
		if (temp->label == holder)
			return temp;
		temp = temp->right;
		} while (temp != CDLL);
	if (temp == CDLL)
		return NULL;
	}
