//Circular linked list ADT structure

#define EMPTY 0

typedef struct node {
	int data;
	struct node* next;
	} cll_node;

typedef struct node* cll_ptr;
	
void insertFirst (cll_ptr*,int);
void insertLast (cll_ptr*,int);
int deleteFirst (cll_ptr*);
int deleteLast (cll_ptr*);

void insertFirst (cll_ptr* CLL, int item) {
	//enter data into new node
	cll_ptr newNode = (cll_ptr) malloc(sizeof(cll_node));
	if (!newNode)
		return; //memory error
	newNode->data = item;
	//if empty list, make new node the first/last node (CLL)
	if (*CLL == NULL) {
		*CLL = newNode;
		(*CLL)->next = *CLL;
		return;
		}
	//add new node to front of CLL
	newNode->next = (*CLL)->next;
	(*CLL)->next = newNode;
	}
	
void insertLast (cll_ptr* CLL, int item) {
	//enter data into new node
	cll_ptr newNode = (cll_ptr) malloc(sizeof(cll_node));
	if (!newNode)
		return; //memory error
	newNode->data = item;
	//if empty list, make new node the first/last node (CLL)
	if (*CLL == NULL) {
		*CLL = newNode;
		(*CLL)->next = *CLL;
		return;
		}
	//add new node to end of CLL
	newNode->next = (*CLL)->next;
	(*CLL)->next = newNode;
	*CLL = newNode;
	}
	
int deleteFirst (cll_ptr* CLL) {
	//if empty list
	if (!(*CLL))
		return EMPTY;
	//store data of first node temporarily
	cll_ptr temp = (*CLL)->next;
	int item = temp->data;
	//if single element list, delete that node
	if (temp == *CLL) {
		*CLL = NULL;
		free(temp);
		return item;
		}
	//connect last node to second node and delete first node
	(*CLL)->next = temp->next;
	free(temp);
	//return deleted data
	return item;
	}
	
int deleteLast (cll_ptr* CLL) {
	//if empty list
	if (!(*CLL))
		return EMPTY;
	//store data of last node temporarily
	cll_ptr last = *CLL, temp = *CLL;
	int item = last->data;
	//if single element list, delete that node
	if ((*CLL)->next == *CLL) {
		*CLL = NULL;
		free(last);
		return item;
		}
	//traverse list to find second-last node
	while (temp->next != *CLL) {
		temp = temp->next;
		}
	//connect second-last node to first node and delete last node
	temp->next = (*CLL)->next;
	*CLL = temp;
	free(last);
	//return deleted data
	return item;
	}
