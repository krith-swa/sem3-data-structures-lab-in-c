//implementation of graph ADT - bfs and dfs

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graph.h"

struct City {
	char name[MAX_SIZE][MAX_SIZE];
	int code;
	};
typedef struct City* city;

void dfsFlight (graph,city,int,int);
int bfsFlight (graph,int,int);
int getIndex (city,char*);
void printAdjMatrix (graph);
void printAdjMatrixFlight (graph);
int reached;

int main() {
	char cmd[50];
	
	do {
		printf("\nEnter test choice - (disconnected, friends or flight): ");
		scanf("%s",cmd);
		
		if (strcmp(cmd,"disconnected")==0) {
			printf("\n__TESTING A DISCONNECTED GRAPH__\n");

			int numV, numE, maxE;

			printf("\n__Create graph__\n");
			printf("Enter number of vertices: ");
			scanf("%d",&numV);
			graph g1 = createGraph(numV);

			maxE = numV*(numV-1)/2;

			printf("Enter edges: (vertex1-vertex2) (enter invalid edge to quit)\n");
			int v1,v2;
			numE=0;
			do {
				scanf("%d-%d",&v1,&v2);
				if (v1>0 && v2>0) {
					insertEdge(g1,v1-1,v2-1);
					numE++;
					}
				} while(numE<=maxE && (v1>0 && v2>0));

			printf("\n\nAdjacency matrix of the disconnected graph:");
			printAdjMatrix(g1);

			int start;
			printf("Enter starting vertex: ");
			scanf("%d",&start);

			//printf("\nDFS Traversal: \n");
			//dfs(g1,start-1);
			printf("\nBFS Traversal: \n");
			printbfs(g1,start-1);
			printf("\n\n");
			}
		
		else if (strcmp(cmd,"friends")==0) {
			printf("\n__FRIENDSHIP RELATION__\n");
			
			int numV, numE, maxE;
			
			printf("\n__Create graph with people as vertices and relations given by edges__\n");
			printf("Enter number of people: ");
			scanf("%d",&numV);
			graph g2 = createGraph(numV);

			maxE = numV*(numV-1)/2;

			printf("Enter pair of friends: (vertex1-vertex2) (enter invalid friendship to quit)\n");
			int v1,v2;
			numE=0;
			do {
				scanf("%d-%d",&v1,&v2);
				if (v1>0 && v2>0) {
					insertEdge(g2,v1-1,v2-1);
					numE++;
					}
				} while(numE<=maxE && (v1>0 && v2>0));

			printf("\n\nAdjacency matrix of the friendship graph:");
			printAdjMatrix(g2);
			
			int x, y;			
			printf("Enter pair of people to introduce: ");
			scanf("%d %d", &x, &y);
			
			//printf("BFS Traversal: ");
			//printbfs(g2,x-1);
			printf("\n\n");
			
			int find = bfsSearch(g2,x-1,y-1);
			clearVisited(g2);
			//dfsSearch(g2,x-1,y-1);
			if (find == -1)
				printf("\nThe given pair of people cannot be introduced!\n");
			else
				printf("\nThey can be introduced!\n");
			printf("\n");
			}
			
		else if (strcmp(cmd,"flight")==0) {
			printf("\n__FLIGHT ROUTES__\n");
			
			city C = (city) malloc(sizeof(struct City));
			C->code = 0;
			
			char flight1[MAX_SIZE], flight2[MAX_SIZE];
			int numV, numE, maxE;
			
			printf("\n__Create graph with flight schedule__\n");
			printf("Enter number of cities: ");
			scanf("%d",&numV);
			graph flights = createGraph(numV);

			maxE = numV*(numV-1)/2;
		        
		        printf("Enter direct flights: (vertex1 vertex2) (enter nil nil to quit)\n");
			int v1,v2;
			numE=0;
			do {
				printf("Enter the number of direct flights: ");
				scanf("%d",&numE);
				if (numE > maxE) 
					printf("Number of direct flights cannot exceed %d. Enter again.",maxE);
				} while (numE>maxE);
		        
				printf("Enter direct flights:\n");
				for (int i=0; i<numE; i++) {
					int f1, f2;
					scanf("%s %s", flight1,flight2);
					f1 = getIndex(C,flight1);
					f2 = getIndex(C,flight2);
					insertEdgeD(flights,f1,f2);
					}
				
				printAdjMatrixFlight(flights);				
				
				char src[MAX_SIZE], dest[MAX_SIZE];

				printf("Enter pair of cities to check for direct flights: ");
				memset(flights->visited,0,sizeof(flights->visited));
				scanf("%s %s",src,dest);

				while (strcmp(src,"nil") && strcmp(dest,"nil")) {
					reached = 0;				
					if (getIndex(C,src) <= flights->size && getIndex(C,dest) <= flights->size) {
						int s = getIndex(C,src), d = getIndex(C,dest);
						if (flights->adj[s][d])
							printf("\nDirect flight available: %s -> %s\n",C->name[s],C->name[d]);
						else {
							clearVisited(flights);
							
							printf("Checking for connecting flights\n");
							dfsFlight(flights,C,s,d);						
							}
						}
					else
						printf("City not found\n");
					printf("\n");

					printf("Enter pair of cities to check for direct flights: ");
					clearVisited(flights);
					scanf("%s %s",src,dest);
					}
			}
		
		} while (strcmp(cmd,"exit"));
	}
	
void dfsFlight (graph G, city C, int source, int dest) {
	G->visited[source]++;
	if (source != dest && reached==0)
		printf("%s -> ", C->name[source]);
	if (source == dest) {
		printf("%s \n", C->name[source]);
		reached = 1;
		return;
		}
	for (int i = 1; i <= G->size; i ++) {
        	if (i!=source) {
			if (G->adj[source][i] && G->visited[i]<2) {
		    		dfsFlight(G,C,i,dest);
		    		}
            		}
        	}
	return;
	}

int bfsFlight (graph G, int vertex, int dest) {
	queue_ptr queue = createQueue(MAX_SIZE);

	enqueue(queue,vertex);
	G->visited[vertex] = 1;
	
	while (!isEmpty(queue)) {
		int u = dequeue(queue);
		if (u==dest)
			return 1;
		for (int i=1; i<=G->size; i++) {
			if (G->adj[u][i] && !G->visited[i]) {
				G->visited[i] = 1;
				enqueue(queue, i);
				}
			}
		}
	return -1;
	}
	
int getIndex (city C, char* findCity) {
	for (int i=1; i<=C->code; i++) {
		if (!strcmp(C->name[i],findCity))
			return i;
		}
	strcpy(C->name[++C->code],findCity);
	return C->code;
	}

void printAdjMatrix (graph G) {
	int size = G->size;
	printf("\n     ");
	for (int i=1; i<=size; i++)
		printf("%d   ",i);
	printf("\n\n");
	for (int i=0; i<size; i++) {
		printf("%d    ",i+1);
		for (int j=0; j<size; j++) {
			printf("%d   ",G->adj[i][j]);
			}
		printf("\n");
		}
	printf("\n");
	}

void printAdjMatrixFlight (graph G) {
	int size = G->size;
	printf("\n     ");
	for (int i=1; i<=size; i++)
		printf("%d   ",i);
	printf("\n\n");
	for (int i=1; i<=size; i++) {
		printf("%d    ",i);
		for (int j=1; j<=size; j++) {
			printf("%d   ",G->adj[i][j]);
			}
		printf("\n");
		}
	printf("\n");
	}
