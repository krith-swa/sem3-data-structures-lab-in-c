//Graph ADT Structure

#define MAX_SIZE 20
#include "queue.h"

struct Graph {
	int adj[MAX_SIZE][MAX_SIZE];
	int size;
	int visited[MAX_SIZE];
	};
typedef struct Graph* graph;

graph createGraph (int);
void dfs (graph,int);
void bfs (graph,int);
void printbfs (graph,int);
int bfsSearch (graph,int,int);
void dfsSearch (graph,int,int);
void clearVisited(graph);
void initVertices (graph,int);
void insertEdgeD (graph,int,int);
void insertEdge (graph,int,int);

graph createGraph (int numVertices) {
	graph newGraph = (graph) malloc (sizeof(struct Graph));
	newGraph->size = numVertices;
	for (int i=0; i<numVertices; i++) {
		newGraph->visited[i] = 0;
		for (int j=0; j<numVertices; j++)
			newGraph->adj[i][j] = 0;
		}
	return newGraph;
	}

void dfs (graph G, int start) {
	int vertex = start;
	G->visited[vertex] = 1;
	printf("%d ",vertex+1);
	for (int i=1; i<=G->size; i++) {
		if (G->adj[vertex][i] && !G->visited[i]) {
			dfs(G,i);
			}
		}
	}

void bfs (graph G, int start) {
	int vertex = start;
	queue_ptr queue = createQueue(MAX_SIZE);
	
	enqueue(queue,vertex);
	G->visited[vertex] = 1;
	
	while (!isEmpty(queue)) {
		int u = dequeue(queue);
		printf("%d ", u+1);
		for (int i=0; i<G->size; i++) {
			if (G->adj[u][i] && !G->visited[i]) {
				G->visited[i] = 1;
				enqueue(queue,i);
				}
			}
		}
	}
	
void dfsSearch (graph G, int start, int dest) {
	int vertex = start;
	G->visited[vertex] = 1;
	printf("%d ",vertex+1);
	if (vertex == dest)
		return;
	for (int i=1; i<=G->size; i++) {
		if (G->adj[vertex][i] && !G->visited[i]) {
			dfs(G,i);
			}
		}
	}
	
void printbfs (graph G, int start) {
	int vertex = start;
	queue_ptr queue = createQueue(MAX_SIZE);
	clearVisited(G);
	
	enqueue(queue,vertex);
	G->visited[vertex] = 1;
	
	while (!isEmpty(queue)) {
		int u = dequeue(queue);
		printf("%d ", u+1);
		G->visited[u]==2;
		for (int i=0; i<G->size; i++) {
			if (G->adj[u][i]==1 && G->visited[i]==0) {
				G->visited[i] = 1;
				enqueue(queue,i);
				}
			}
		}
		
	for (int v=0; v<G->size; v++) {
		if (!G->visited[v]) {
			printf("\n");
			vertex = v;
			
			enqueue(queue,vertex);
			G->visited[vertex] = 1;
			
			while (!isEmpty(queue)) {
				int u = dequeue(queue);
				printf("%d ", u+1);
				G->visited[u]==2;
				for (int i=0; i<G->size; i++) {
					if (G->adj[u][i]==1 && G->visited[i]==0) {
						G->visited[i] = 1;
						enqueue(queue,i);
						}
					}
				}
			}
		}
	}
	
int bfsSearch (graph G, int start, int dest) {
	int vertex = start;
	queue_ptr queue = createQueue(MAX_SIZE);

	clearVisited(G);
	
	enqueue(queue,vertex);
	G->visited[vertex] = 1;
	
	while (!isEmpty(queue)) {
		int u = dequeue(queue);
		printf("%d ", u+1);
		G->visited[u]==2;
		
		if (u==dest)
			return 1;
		
		for (int i=0; i<G->size; i++) {
			if (G->adj[u][i]==1 && G->visited[i]==0) {
				G->visited[i] = 1;
				enqueue(queue,i);
				}
			}
		}
	return -1;
	}
	
void clearVisited (graph G) {
	for (int i=0; i<G->size; i++)
		G->visited[i]=0;
	}
	
void initVertices (graph G, int size) {
	G->size = size;
	}

void insertEdgeD (graph G, int vertex1, int vertex2) {
	G->adj[vertex1][vertex2] = 1;
	}

void insertEdge (graph G, int vertex1, int vertex2) {
	G->adj[vertex1][vertex2] = 1;
	G->adj[vertex2][vertex1] = 1;
	}
