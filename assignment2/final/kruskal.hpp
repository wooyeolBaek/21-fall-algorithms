#include "disjointset.hpp"



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
