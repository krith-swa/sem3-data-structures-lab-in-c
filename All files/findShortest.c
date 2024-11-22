//implementing dijkstra's algorithm to find the shortest path to different destinations from a single source

#include <stdio.h>
#include <stdlib.h>
#include "dijGraph.h"

void dijkstra(graph,int);
void printSolution(int[],int);
	
void dijkstra (graph G, int source) {
	int dist[G->size];
	pqHeap shortest = createPQ(G->size);
	
	for (int i=0; i<G->size; i++)
		dist[i] = INF;
		
	dist[source] = 0;
	shortest = insertPQ(shortest,dist[source],source);
	
	while (!isEmpty(shortest)) {
		int closeV = deleteMin(shortest);
		
		for (int v=0; v<G->size; v++) {
			if (G->adj[closeV][v] && dist[closeV]!=INF && dist[closeV]+G->adj[closeV][v]<dist[v]) {
				dist[v] = dist[closeV] + G->adj[closeV][v];
				shortest = insertPQ(shortest,dist[v],v);
				}
			}
		}
	
	printSolution(dist,G->size);
	}

int main() {
	int numV, numE, maxE;
	graph g1 = (graph) malloc (sizeof(struct Graph));
	
	printf("\n__CREATE GRAPH__\n\n");
	printf("Enter number of vertices: ");
	scanf("%d",&numV);
	initVertices(g1,numV);
	
	maxE = numV*(numV-1)/2;
	
	printf("Enter edges: (vertex1-vertex2:weight) (enter invalid edge to quit)\n");
	int v1,v2,weight;
	numE=0;
	do {
		scanf("%d-%d:%d",&v1,&v2,&weight);
		if (v1>=0 && v2>=0 && weight>=0) {
			insertEdge(g1,v1,v2,weight);
			numE++;
			}
		} while(numE<=maxE && (v1>=0 && v2>=0 && weight>=0));
	
	printf("\n\nAdjacency matrix of the graph:");
	printAdjMatrix(g1);
	
	printf("\n\n__FINDING SHORTEST PATH FROM SOURCE__\n");
	int src;
	src=0;
	dijkstra(g1,src);
	
	return 0;
	}
	
void printSolution (int dist[], int numV) {
	printf("Vertex \t\t Distance from Source\n");
	for (int i=0; i<numV; i++)
		printf("%d \t\t %d\n",i,dist[i]);
	}

/*	
void printSolutionPath (pqHeap pq) {
	printf("Vertex \t\t Distance from Source\n");
	for (int i=0; i<pq->size; i++)
		printf("%d \t\t %d\n",pq->value[i],pq->key[i]);
	}
*/
