#include "dijkstra.hpp"

int main(){
	//Figure 4.8
	std::cout<<"Figure 4.8\n";

	int W[N + 1][N + 1] = { {0,0,0,0,0,0},
							{0,0,7,4,6,1},
							{0,INF,0,INF,INF,INF},
							{0,INF,2,0,5,INF},
							{0,INF,3,INF,0,INF},
							{0,INF,INF,INF,1,0}
	};

	dijkstra(N, W, F);
	
	for (int i = 0; i < f_idx; i++){
		std::cout<<"edge: v"<<F[i].v1<<" -> v"<<F[i].v2<<", shortest path from v1->v"<<F[i].v2<<" = "<<F[i].w<<"\n";
	}
	std::cout<<"\n";
	f_idx = -1;



	//My graph
	std::cout<<"My digraph\n";

	int W2[N + 1][N + 1] = { {0,0,0,0,0,0},
							{0,0,6,INF,3,1},
							{0,INF,0,1,INF,2},
							{0,3,INF,0,INF,INF},
							{0,INF,INF,3,0,INF},
							{0,INF,INF,2,1,0}
	};


	set_of_edges F;

	dijkstra(N, W2, F);

	for (int i = 0; i < f_idx; i++){
		std::cout<<"edge: v"<<F[i].v1<<" -> v"<<F[i].v2<<", shortest path from v1->v"<<F[i].v2<<" = "<<F[i].w<<"\n";
	}
	std::cout<<"\n";
	f_idx = -1;

	return 0;
}


