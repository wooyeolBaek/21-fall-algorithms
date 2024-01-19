#include <iostream>
#define N 5
#define INF 99999

const int m = 7;

struct edge{
	int w;//weight
	int v1;
	int v2;
};

typedef edge set_of_edges[N];

void dijkstra(int n, int W[][N + 1], set_of_edges& F);

int f_idx = -1;

int main(){
	int W[N + 1][N + 1] = { {0,0,0,0,0,0},
							{0,0,7,4,6,1},
							{0,INF,0,INF,INF,INF},
							{0,INF,2,0,5,INF},
							{0,INF,3,INF,0,INF},
							{0,INF,INF,INF,1,0}
	};


	set_of_edges F;

	dijkstra(N, W, F);

	for (int i = 0; i < f_idx; i++){
		std::cout<<"edge: v"<<F[i].v1<<" -> "<<F[i].v2<<", weight="<<F[i].w<<"\n";
	}
}


void dijkstra(int n, int W[][N+1], set_of_edges& F){
	int i, vnear;
	edge e;
	int touch[N + 1];
	int length[N + 1];

	//F = the empty set
	for (i = 0; i < m; i++){
		F[i].v1 = 0;
		F[i].v2 = 0;
		F[i].w = 0;
	}

	//For all vertices, initialize v1
	for (i = 2; i <= n; i++){
		touch[i] = 1;
		length[i] = W[1][i];
	}

	while (f_idx != n - 1){
		int min = INF;
		for (i=2; i <= n; i++){
			if (0 <= length[i] && length[i]<= min){
				min = length[i];
				vnear = i;
			}
		}
		
		//e = edge from vertex indexed by touch[vnear] to vertex indexed by vnear
		e.v1 = touch[vnear];
		e.v2 = vnear;
		e.w = W[e.v1][e.v2];

		F[++f_idx] = e;//add e to F

		for (i = 2; i <= n; i++){
			if (length[vnear] + W[vnear][i] < length[i]){
				length[i] = length[vnear] + W[vnear][i];
				touch[i] = vnear;
			}
		}
		length[vnear] = -1;
	}
}