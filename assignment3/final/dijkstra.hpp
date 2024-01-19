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

set_of_edges F;

int f_idx = -1;//index of F

void dijkstra(int n, int W[][N+1], set_of_edges& F){
	int i, vnear;//vnear: index of touch
	edge e;
	int touch[N + 1];
	int length[N + 1];

	//F = the empty set
	for (i = 0; i < m; i++){
		F[i].v1 = 0;
		F[i].v2 = 0;
		F[i].w = 0;
	}

	//initialize touch, length: v1 -> vi
	for (i = 2; i <= n; i++){
		touch[i] = 1;
		length[i] = W[1][i];
	}

	while (f_idx != n - 1){//repeat n-1 times
		int min = INF;
		for (i=2; i <= n; i++){
			if (0<=length[i] && length[i]<min){//when it has a shortest path
				min = length[i];
				vnear = i;
			}
		}
		
		//e = edge from vertex indexed by touch[vnear] to vertex indexed by vnear
		e.v1 = touch[vnear];
		e.v2 = vnear;
		e.w = length[vnear];//shortest length from v1 to vvnear

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