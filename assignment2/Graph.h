// Graph ADT interface ... COMP9024 18s2z
#include <stdbool.h>
#include "queue.h"

typedef struct GraphRep *Graph;

// vertices are ints
typedef int Vertex;

// edges are pairs of vertices (end-points)
typedef struct Edge {
   Vertex v;
   Vertex w;
} Edge;

Graph newGraph(int);
int   numOfVertices(Graph);
void  insertEdge(Graph, Edge);
void  removeEdge(Graph, Edge);
bool  adjacent(Graph, Vertex, Vertex);
void   showGraph(Graph);
void  freeGraph(Graph);
queue find_path(Graph);
void dfsfind(int ,queue,Graph);
int find_max_sequence_lenth(Graph);