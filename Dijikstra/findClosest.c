//implementing dijkstra's algorithm to find the shortest path to different destinations from a single source

#include <stdio.h>
#include <stdlib.h>
#include "dijkstra.h"

void printSolution (int dist[], int numV) {
	printf("Vertex \t\t Distance from Source\n");
	for (int i=0; i<numV; i++)
		printf("%d \t\t %d\n",i,dist[i]);
	}
	
void dijkstra (graph G, int source) {
	int dist[G->size];
	bool shortest[G->size];
	
	for (int i=0; i<G->size; i++) {
		dist[i] = INF;
		shortest[i] = false;
		}
		
	dist[source] = 0;
	
	for (int vertex=0; vertex<G->size; vertex++) {
		int closeV = minDistance(G,dist,shortest);
		shortest[closeV] = true;
		
		for (int v=0; v<G->size; v++) {
			if (!shortest[v] && G->adj[closeV][v] && dist[closeV]!=INF && dist[closeV]+G->adj[closeV][v]<dist[v])
				dist[v] = dist[closeV] + G->adj[closeV][v];
			}
		}
		
	printSolution (dist,G->size);
	}

int main() {
	graph g1 = (graph) malloc (sizeof(struct Graph));
	
	initVertices(g1,9);
	
	insertEdge(g1,0,1,4);
	insertEdge(g1,0,7,8);
	insertEdge(g1,1,2,8);
	insertEdge(g1,1,7,11);
	insertEdge(g1,2,3,7);
	insertEdge(g1,2,8,2);
	insertEdge(g1,2,5,4);
	insertEdge(g1,3,4,9);
	insertEdge(g1,3,5,14);
	insertEdge(g1,4,5,10);
	insertEdge(g1,8,6,6);
	insertEdge(g1,7,6,1);
	insertEdge(g1,6,5,2);
	insertEdge(g1,7,8,7);
	
	printAdjMatrix(g1);
	
	dijkstra(g1,0);
	
	return 0;
	}
