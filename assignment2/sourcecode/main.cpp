//#include "disjointcopycopycopy.hpp"
#include "kruskal.hpp"

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
