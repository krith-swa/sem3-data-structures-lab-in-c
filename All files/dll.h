//Doubly linked list ADT structure

#define EMPTY 0

typedef struct node {
	int data;
	struct node* right;
	struct node* left;
	} dll_node;

typedef struct node* dll_ptr;
	
void insertFirst (dll_ptr*,int);
void insertLast (dll_ptr*,int);
int deleteFirst (dll_ptr*);
int deleteLast (dll_ptr*);

void insertFirst (dll_ptr* DLL, int item) {
	//enter data into new node
	dll_ptr newNode = (dll_ptr) malloc(sizeof(dll_node));
	if (!newNode)
		return; //memory error
	newNode->data = item;
	//if empty list, make new node the first/last node (DLL)
	if (!(*DLL)) {
		*DLL = newNode;
		(*DLL)->right = NULL;
		(*DLL)->left = NULL;
		return;
		}
	//add new node to front of DLL
	newNode->right = *DLL;
	newNode->left = NULL;
	(*DLL)->left = newNode;
	*DLL = newNode;
	}
	
void insertLast (dll_ptr* DLL, int item) {
	//enter data into new node
	dll_ptr newNode = (dll_ptr) malloc(sizeof(dll_node));
	if (!newNode)
		return; //memory error
	newNode->data = item;
	//if empty list, make new node the first/last node (DLL)
	if (!(*DLL)) {
		*DLL = newNode;
		(*DLL)->right = NULL;
		(*DLL)->left = NULL;
		return;
		}
	//add new node to end of DLL
	dll_ptr temp = *DLL;
	newNode->right = NULL;
	while (temp->right != NULL) 
		temp = temp->right;
	temp->right = newNode;
	newNode->left = temp;
	}
	
int deleteFirst (dll_ptr* DLL) {
	//if empty list
	if (!(*DLL))
		return EMPTY;
	//store data of first node temporarily
	dll_ptr temp = *DLL;
	int item = temp->data;
	//if single element list, delete that node
	if (temp->right == NULL) {
		*DLL = NULL;
		free(temp);
		return item;
		}
	//delete first node
	*DLL = (*DLL)->right;
	(*DLL)->left = NULL;
	temp->right = NULL;
	free(temp);
	//return deleted data
	return item;
	}
	
int deleteLast (dll_ptr* DLL) {
	//if empty list
	if (!(*DLL))
		return EMPTY;
	dll_ptr temp = *DLL;
	int item;
	//if single element list, delete that node
	if ((*DLL)->right == NULL) {
		*DLL = NULL;
		item = temp->data;
		free(temp);
		return item;
		}
	//traverse list to find last and second-last nodes
	dll_ptr prev = NULL;
	while (temp->right != NULL) {
		prev = temp;
		temp = temp->right;
		}
	//store data of last node temporarily
	item = temp->data;
	//delete last node
	temp->left = NULL;
	prev->right = NULL;
	free(temp);
	//return deleted data
	return item;
	}
