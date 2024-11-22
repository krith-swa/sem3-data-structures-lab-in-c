//implementation of queue ADT using circular arrays

int spool (queue_ptr,int);
int print (queue_ptr);
void list (queue_ptr);
void dispMenu();

int spool (queue_ptr queue, int jobID) {
	if (isFull(queue))
		return -1; //queue full
	enqueue(queue,jobID);
	return 1;
	}

int print (queue_ptr queue) {
	if (isEmpty(queue))
		return -1; //queue empty
	unsigned jobID = dequeue(queue);
	return jobID;
	}

void list (queue_ptr queue) {
	if (isEmpty(queue))
		return;//validate - printf("Queue is empty.\n");
	//printf("Circular queue: ");
	if (queue->rear >= queue->front) {
		for (int i=queue->front; i<=queue->rear; i++)
			printf("%d  ",queue->array[i]);
		}
	else {
		for (int i=queue->front; i<queue->capacity; i++)
			printf("%d  ",queue->array[i]);
		for (int i=0; i<=queue->rear; i++)
			printf("%d  ",queue->array[i]);
		}
	printf("\n");
	}

int main() {
	//create queue
	printf("__PRINTER SPOOLER__\n");
	int size;
	printf("Enter capacity of printer queue: ");
	scanf("%d",&size);
	queue_ptr queue = createQueue(size);
	
	//printer spooler interface - menu
	int choice;
	dispMenu();
	do {
		printf("\nEnter choice: ");
		scanf("%d",&choice);
		
		switch (choice) {
			case 1: {
				unsigned jobID;
				printf("\nEnter job's ID no.: ");
				scanf("%u",&jobID):
				int check = spool(queue,jobID);
				if (check==1)
					printf("Job submitted successfully.\n");
				else if (check==-1)
					printf("Queue is full. Wait before addition of a new job.\n");
				else
					printf("Error! Operation unsuccessful.\n");
				break;
				}
			
			case 2: {
				int job = print(queue);
				if (job==-1)
					printf("Queue is empty. Add some jobs to perform.\n");
				else 
					printf("Job %d performed successfully.\n");
				break;
				}
				
			case 3: {
				printf("Jobs in queue: ");
				list(queue);
				break;
				}
			
			case 0: printf("Exiting menu...\n");
				break;
				
			case -1: dispMenu();
				break;
				
			default: printf("Invalid option! Enter integer in range [-1,3] only.\n");
			}
		} while (choice != 0);
		
	return 0;
	}
	
void dispMenu() {
	printf("__MENU__\n");
	printf(" 1: spool()-add a job to the printer queue\n 2: print()-execute job at front of queue\n");
	printf(" 3: list()-list the jobs in queue in spooled order\n");
	printf(" 0: exit menu\n-1: display menu\n");
	}
