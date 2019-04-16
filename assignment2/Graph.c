// Graph ADT
// Adjacency Matrix Representation ... COMP9024 18s2
#include "Graph.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
typedef struct GraphRep {
   int  **edges;   // adjacency matrix
   int    nV;      // #vertices
   int    nE;      // #edges;
   int    *mark;   //mark the whether the vertex can go further
   queue maxpath;//use a queun to store the maxpath
} GraphRep;

Graph newGraph(int V) {
   assert(V >= 0);
   int i;
   Graph g = malloc(sizeof(GraphRep));
   assert(g != NULL);
   g->nV = V;
   g->nE = 0;
   g->mark = calloc(V, sizeof(int));
   assert(g->mark != NULL);
   g->maxpath=NULL;//initial the maxpath to null
   for (i = 0; i < V; i++) {
     g->mark[i]=1;
   }
   // allocate memory for each row
   g->edges = malloc(V * sizeof(int *));
   assert(g->edges != NULL);
   // allocate memory for each column and initialise with 0
   for (i = 0; i < V; i++) {
      g->edges[i] = calloc(V, sizeof(int));
      assert(g->edges[i] != NULL);
   }

   return g;
}
// check if vertex is valid in a graph
bool validV(Graph g, Vertex v) {
   return (g != NULL && v >= 0 && v < g->nV);
}

void insertEdge(Graph g, Edge e) {
   assert(g != NULL && validV(g,e.v) && validV(g,e.w));

   if (!g->edges[e.v][e.w]) {  // edge e not in graph
      g->edges[e.v][e.w] = 1;
      //g->edges[e.w][e.v] = 1;
      g->nE++;
   }
}

void removeEdge(Graph g, Edge e) {
   assert(g != NULL && validV(g,e.v) && validV(g,e.w));

   if (g->edges[e.v][e.w]) {   // edge e in graph
      g->edges[e.v][e.w] = 0;
      //g->edges[e.w][e.v] = 0;
      g->nE--;
   }
}

bool adjacent(Graph g, Vertex v, Vertex w) {
   assert(g != NULL && validV(g,v) && validV(g,w));

   return (g->edges[v][w] != 0);
}

void showGraph(Graph g) {
    assert(g != NULL);
    int i, j;
    printf("Number of vertices: %d\n", g->nV);
    //printf("Number of edges: %d\n", g->nE);
    for (i = 0; i < g->nV; i++){
        for (j = i+1; j < g->nV; j++){
            if (g->edges[i][j]){
               // printf("Edge %d - %d\n", i, j);
            }
        }
    }
}

void freeGraph(Graph g) {
   assert(g != NULL);
   int i;
   for (i = 0; i < g->nV; i++){
    free(g->edges[i]);
    free(g->edges);
    free(g->mark);
    free(g);
    }
}
int find_max_sequence_lenth(Graph g){
    int i,j;
    int n=g->nV;
    int *max=calloc(n,sizeof(int));
    static int max_sequence_lenth=0; 
    for( i=0;i<n;i++){
        for (j=i+1;j<n;j++){
            if(adjacent(g,i,j)&&max[j]<=max[i]+1){
                max[j]=max[i]+1;
                if(max[j]>max_sequence_lenth){
                    max_sequence_lenth=max[j];
                }
            }
        }
    }
    max_sequence_lenth+=1;//includeing the initial one
    free(max);
return max_sequence_lenth;
}

void dfsfind(int vertex,queue current_path,Graph g){
    int flag=0;//
    int next=vertex+1;
    int node=g->nV;
    while(next<node){
        if(g->edges[vertex][next]==1){
            flag=1;
            g->mark[next]=0;
            int a=0;
            queue append_path=newQueue();
            while(a<get_queue_lenth(current_path)){// store the current path,and twe don't want to loose the information,s
                int p=QueueDequeue(current_path);// here is a deepcopy like python
                QueueEnqueue(append_path,p);
                QueueEnqueue(current_path,p);
                a++;
            }
            QueueEnqueue(append_path,next);
            dfsfind(next,append_path,g);
        }
        next++;
    }
    if(flag==1){
        dropQueue(current_path);//if its flag is 1,it is shorter then mean we find a path which is greater then it in terms of the lenth
    }
    else{
        if(g->maxpath==NULL){//if we meet the end of the vertertx,it must be the longgest path
            g->maxpath=current_path;
        }
        else{
            if(get_queue_lenth(g->maxpath)<get_queue_lenth(current_path)){
                queue temp=g->maxpath;
                g->maxpath=current_path;
                //printf("I am in before droptemp\n");
                dropQueue(temp);
            }
            else{
                dropQueue(current_path);}
        }
    }
}
//for all vertex do a dfs search
queue find_path(Graph g){
    int i;
    int nodes=g->nV;
    for(i=0;i<nodes;i++){
        if(g->mark[i]==1){
            queue path=newQueue();
            QueueEnqueue(path,i);
            dfsfind(i,path,g);
        }
    }
return g->maxpath;
}

