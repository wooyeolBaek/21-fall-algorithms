#include <iostream>

//disjoint set data structure 2
const int n = 5; //the number of smallest elements in the universe
const int m = 7;

//typedef int index;
typedef int set_pointer;

struct nodetype{
    int parent;//parent node
    int depth;//node depth
};

typedef nodetype universe[n+1];//universe in indexed, from 1 to n

universe U;//array of nodetypes, the set of vertices, length==n+1 not going to use U[0]

void makeset(int i){//make U[i] == root node
    U[i].parent = i;
    U[i].depth = 0;
}

set_pointer find(int i){//find root node of node i
    int j;
    j = i;
    while(U[j].parent != j){
        j = U[i].parent;
    }
    return j;
}

void merge(set_pointer p, set_pointer q){//assume p,q have a different root node, make p, q are in the same tree
    if(U[p].depth == U[q].depth){// if p,q have the same depth
        U[p].depth = U[q].depth + 1;//connect p and q, 
        U[q].parent = p;
    }
    else if(U[p].depth < U[q].depth){//connect nodes with a smaller depth to another node
        U[p].parent = q;
    }
    else{
        U[q].parent = p;
    }
}

bool equal(set_pointer p, set_pointer q){//determine p,q are the same
    if(p==q){
        return true;
    }
    else{
        return false;
    }
}

void initial(int n){//make set from 1 to n
    int i;
    for(i=1;i<=n;i++){
        makeset(i);
    }
}

/*
//additional structures and functions
struct edge{
	int w;//weight
	int v1;//vertex1
	int v2;//vertex2
};

typedef edge set_of_edges[m];
set_of_edges E;
int e_idx = -1;//array E index
int f_idx = -1;//array F index

//insert edges to E
void makeedge(int vtx1, int vtx2, int wgt){
	E[++e_idx].v1 = vtx1;
	E[e_idx].v2 = vtx2;
	E[e_idx].w = wgt;
}
*/