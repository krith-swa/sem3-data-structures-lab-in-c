//Graph structure for Dijkstra's algorithm

#include <stdbool.h>
#define MAX_V 20
#define INF 200

struct Graph {
	int adj[MAX_V][MAX_V];
	int size;
	};
typedef struct Graph* graph;

int minDistance (graph G, int dist[], bool shortest[]) {
	int min = INF, min_index;
	
	for (int v=0; v<G->size; v++) {
		if (!shortest[v] && dist[v]<min) {
			min = dist[v];
			min_index = v;
			}
		}
	
	return min_index;
	}
	
void initVertices(graph G, int size) {
	G->size = size;
	}

void insertEdge(graph G, int vertex1, int vertex2, int weight) {
	G->adj[vertex1][vertex2] = weight;
	G->adj[vertex2][vertex1] = weight;
	}
	
void printAdjMatrix (graph G) {
	int size = G->size;
	printf("    ");
	for (int i=1; i<=size; i++)
		printf("%d  ",i);
	printf("\n\n");
	for (int i=0; i<size; i++) {
		printf("%d   ",i+1);
		for (int j=0; j<size; j++) {
			int weight = G->adj[i][j];
			if (weight>=10)
				printf("%d ",G->adj[i][j]);
			else
				printf("%d  ",G->adj[i][j]);
			}
		printf("\n");
		}
	printf("\n");
	}
