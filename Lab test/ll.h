//list ADT structure

#define EMPTY -1
#define SIZE 5

struct node {
	int data;
	struct node* next;
	};
typedef struct node* pnode;

pnode insertFirst (pnode linklist, int item) {
	//enter data into new node
	pnode newNode = (pnode) malloc(sizeof(struct node));
	if (!newNode)
		return NULL; //memory error. validate
	newNode->data = item;
	//add new node to head of linked list
	newNode->next = linklist;
	linklist = newNode;

	return linklist;
	}

pnode insertLast (pnode linklist, int item) {
	//enter data into new node
	pnode newNode = (pnode) malloc(sizeof(struct node));
	if (!newNode)
		return NULL; //memory error
	newNode->data = item;
	newNode->next = NULL;
	//if empty list, make new node the head
	if (!linklist) {
		linklist = newNode;
		return linklist;
		}
	//find last node and add new node to end of linked list
	pnode temp = linklist;
	while (temp->next) {
		temp = temp->next;
		}
	temp->next = newNode;

	return linklist;
	}

	
int deleteFirst (pnode linklist) {
	pnode temp = linklist;
	//if empty list
	if (!linklist)
		return EMPTY;
	//store data of first node temporarily
	int item = temp->data;
	//shift head to second node and delete first node
	linklist = linklist->next;
	free(temp);
	//return deleted data
	return item;
	}
	
int getData (pnode linklist) {
	return linklist->data;
	}

