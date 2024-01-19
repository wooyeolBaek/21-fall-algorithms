//dijkstra
#include <iostream>

typedef struct
{
	int weight;
	int v1;
	int v2;
}edge;

#define N 5
#define INF 1000

void dijkstra(int n, int(*W)[N + 1], edge* F);

int f_index = -1;

int main()
{
	int W[N + 1][N + 1] = { {0,0,0,0,0,0},
						{0,0,7,4,6,1},
						{0,INF,0,INF,INF,INF},
						{0,INF,2,0,5,INF},
						{0,INF,3,INF,0,INF},
						{0,INF,INF,INF,1,0}
	};


	edge F[N];

	dijkstra(N, W, F);

	for (int i = 0; i < f_index; i++){
		std::cout<<F[i].v1<<" -> "<<F[i].v2<<"\n";
	}
}


void dijkstra(int n, int (*W)[N+1], edge *F)
{
	int vnear;
	edge e;

	int touch[N + 1];
	int length[N + 1];

	for (int i = 2; i <= n; i++)
	{
		touch[i] = 1;
		length[i] = W[1][i];
	}

	while (1)
	{


		int min = INF;
		for (int i=2; i <= n; i++)
		{
			if (0 <= length[i] && length[i]<= min)
			{
				min = length[i];
				vnear = i;
			}
		}
		
		e.v1 = touch[vnear];
		e.v2 = vnear;

		F[++f_index] = e;

		for (int i = 2; i <= n; i++)
		{
			if (length[vnear] + W[vnear][i] < length[i])
			{
				length[i] = length[vnear] + W[vnear][i];
				touch[i] = vnear;
			}
		}
		length[vnear] = -1;

		if (f_index == n - 1)
			break;
	}
}