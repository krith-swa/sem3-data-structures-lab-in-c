//list ADT structure

#define EMPTY "none"
#define SIZE 5

struct node {
	char data[SIZE];
	struct node* next;
	};

void insertFirst (struct node**, char[]);
void insertLast (struct node**, char[]);
void insertMiddle (struct node**, char[], char[]);
char* deleteFirst (struct node**, char[]);
char* deleteLast (struct node**, char[]);
void deleteMiddle (struct node**, char[]);
int search (struct node**, char[]);
int length (struct node**);
char* getData (struct node**);

void insertFirst (struct node* *linklist, char item[]) {
	//enter data into new node
	struct node* newNode = (struct node*) malloc(sizeof(struct node));
	if (!newNode)
		return; //memory error. validate?
	strcpy(newNode->data,item);
	//add new node to head of linked list
	newNode->next = *linklist;
	*linklist = newNode;
	}

void insertLast (struct node* *linklist, char item[]) {
	//enter data into new node
	struct node* newNode = (struct node*) malloc(sizeof(struct node));
	if (!newNode)
		return; //memory error
	strcpy(newNode->data,item);
	newNode->next = NULL;
	//if empty list, make new node the head
	if (!(*linklist)) {
		*linklist = newNode;
		return;
		}
	//find last node and add new node to end of linked list
	struct node* temp = *linklist;
	while (temp->next) {
		temp = temp->next;
		}
	temp->next = newNode;
	}
	
void insertMiddle (struct node* *linklist, char item1[], char item2[]) {
	//enter data into new node
	struct node* newNode = (struct node*) malloc(sizeof(struct node));
	if (!newNode)
		return; //memory error
	strcpy(newNode->data,item2);
	
	//find position node
	struct node *curr = *linklist;
		//first occurrence of item1
	/*while (curr!=NULL && strcmp(curr->data,item1)) {
		curr = curr->next;
		} */
		
		//last occurrence of item1
	struct node *last = NULL;
	while (curr!=NULL) {
		if (strcmp(curr->data,item1)==0)
			last = curr;
		curr = curr->next;
		}
	
	//insert new node to linked list
	if (last!=NULL) {
		newNode->next = last->next;
		last->next = newNode;
		}
	}
	
char* deleteFirst (struct node* *linklist, char item[]) {
	struct node *temp = *linklist;
	//if empty list
	if (!(*linklist))
		return EMPTY;
	//if single element list, delete that node
	if (temp->next == NULL) {
		strcpy(item,temp->data);
		*linklist = NULL;
		free(temp);
		return item;
		}
	//store data of first node temporarily
	strcpy(item,temp->data);
	//shift head to second node and delete first node
	*linklist = (*linklist)->next;
	free(temp);
	//return deleted data
	return item;
	}
	
char* deleteLast (struct node* *linklist, char item[]) {
	struct node *temp = *linklist, *prev = NULL;
	//if empty list
	if (!(*linklist))
		return EMPTY;
	//if single element list, delete that node
	if (temp->next == NULL) {
		strcpy(item,temp->data);
		*linklist = NULL;
		free(temp);
		return item;
		}
	//find last node and second-last node
	while (temp->next!=NULL) {
		prev = temp;
		temp = temp->next;
		}
	//store data of last node temporarily
	strcpy(item,temp->data);
	//delete last node
	prev->next = NULL;
	free(temp);
	//return deleted data
	return item;
	}
	
void deleteMiddle (struct node* *linklist, char item[]) {
	struct node *temp = *linklist, *prev;
	//if head node itself contains item to be deleted
	if (temp!=NULL && !strcmp(temp->data,item)) {
		*linklist = temp->next;
		free(temp);
		return;
		}
	//find node that contains item
	while (temp!=NULL && strcmp(temp->data,item)) {
		prev = temp;
		temp = temp->next;
		}
	//delete the node
	if (temp!=NULL) {
		prev->next = temp->next;
		free(temp);
		}
	}

int search (struct node* *linklist, char item[]) {
	struct node* temp = *linklist;
	while (temp!=NULL) {
		if (!strcmp(temp->data,item)) 
			return 1;
		temp = temp->next;
		}
	return 0;
	}
	
int length (struct node* *linklist) {
	int size = 0;
	struct node* curr = *linklist;
	while (curr!=NULL) {
		size++;
		curr = curr->next;
		}
	return size;
	}
	
char* getData (struct node* *linklist) {
	return (*linklist)->data;
	}
