#include <iostream>
#include "disjointset.hpp"


struct edge{
	int w;//weight
	int v1;//vertex1
	int v2;//vertex2
};

typedef edge set_of_edges[m];
set_of_edges E;
int e_idx = -1;//array E index
int f_idx = -1;//array F index

void makeedge(int vtx1, int vtx2, int wgt);
void kruskal(int n, int m, set_of_edges E, set_of_edges& F);


int main(){
	set_of_edges F;

	//Figure 4.7 graph
	makeedge(1, 2, 1);
	makeedge(1, 3, 3);
	makeedge(2, 3, 3);
	makeedge(2, 4, 6);
	makeedge(3, 4, 4);
	makeedge(3, 5, 2);
	makeedge(4, 5, 5);

	kruskal(n, m, E, F);
	std::cout<<"Figure 4.7\n";
	for(int i=0;i<=f_idx;i++){//f_idx==size of F
		std::cout<<"edge: v"<<F[i].v1<<" -> v"<<F[i].v2<<", "<<"weight="<<F[i].w<<"\n";
	}

	//initialize indices
	e_idx = -1;
	f_idx = -1;

	std::cout<<"\n";
	//My graph
	makeedge(1, 2, 1);
	makeedge(1, 3, 6);
	makeedge(1, 4, 5);
	makeedge(2, 3, 3);
	makeedge(2, 4, 4);
	makeedge(2, 5, 2);
	makeedge(3, 5, 7);

	kruskal(n, m, E, F);
	
	std::cout<<"My graph\n";
	for(int i=0;i<=f_idx;i++){//f_idx==size of F
		std::cout<<"edge: v"<<F[i].v1<<" -> v"<<F[i].v2<<", "<<"weight="<<F[i].w<<"\n";
	}


	return 0;
}

void makeedge(int vtx1, int vtx2, int wgt){
	E[++e_idx].v1 = vtx1;
	E[e_idx].v2 = vtx2;
	E[e_idx].w = wgt;
}

void kruskal(int n, int m, set_of_edges E, set_of_edges& F){
	
	int i,j;
	set_pointer p,q;
	edge e;

	//Sort the m edges in E by weight in nondecreasing order
	for (i = 0; i < m-1; i++){
		for (j = i + 1; j < m; j++){
			if (E[i].w > E[j].w){
				edge temp = E[i];
				E[i] = E[j];
				E[j] = temp;
			}
		}
	}
	

	//F = the empty set
	for (i = 0; i < m; i++){
		F[i].v1 = 0;
		F[i].v2 = 0;
		F[i].w = 0;
	}

	//initialize n disjoint subsets
	initial(n);
	

	int edge_count = 0;
	int idx = 0;
	while (edge_count < n-1){//while the number of edges in F is less than n-1
		
		e = E[idx]; //edge with least weight not yet considered
		i = E[idx].v1, j = E[idx].v2; //indices of vertices connected by e
		
		p = find(i);
		q = find(j);
		
		if (!equal(p, q)){
			merge(p, q);
			F[++f_idx] = e;//add e to F
			edge_count++;
		}
		idx++;
	}
}
