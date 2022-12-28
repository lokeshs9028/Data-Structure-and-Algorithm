// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include<limits.h>
#define vertices 5
int minimum_key(int k[], int mst[])
{
	int minimum = INT_MAX, min, i;
	for (i = 0;i < vertices;i++) {
		if (mst[i] == 0 && k[i] < minimum) {
			minimum = k[i];
			min = i;

		}
		
	}
	return min;
}
void prim(int g[vertices][vertices]) {
	int parent[vertices];
	int k[vertices];
	int mst[vertices];
	int i, count, edge, v;
	for (i = 0;i < vertices;i++) {
		k[i] = INT_MAX;
		mst[i] = 0;
	}
	k[0] = 0;
	parent[0] = -1;
	for (count = 0;count < vertices - 1;count++) {
		edge = minimum_key(k, mst);
		mst[edge ]= 1;
		for (v = 0;v < vertices;v++) {
			if (g[edge][v] && mst[v] == 0 && g[edge][v] < k[v]) {
				parent[v] = edge, k[v] = g[edge][v];
			}
		}
	}
	printf("\nEdge \t Weight\n");
	for (i = 1;i < vertices;i++) {
		printf("%d < - > %d %d\n", parent[i], i, g[i][parent[i]]);
		
	}
}
 int main()
{
	/*int edge = 3, vertices = 3, weight[3][3], mst[3][3];
	printf("Enter number of edges: ");
	scanf_s("%d", &edge);
	printf("Enter number of vertices of graph: ");
	scanf_s("%d", &vertices);
	printf("enter weight of the edges: \n");
	for (int i = 1;i <= vertices-1;i++) {
		for (int j = i+1;j <= vertices;j++) {
			printf("Enter the weight of edge %d%d: ", i, j);
			scanf_s("%d", &weight[i][j]);
		}
	}
	for (int i = 1;i <= vertices-1;i++) {
		for (int j = i+1;j <= vertices;j++) {
			printf("Weight of the edge%d%d is :%d", i, j, weight[i][j]);
			printf("\n");
		}
	}
	printf("**********Implementation of Prim's Algorithm *******\n");
	*/
	 int g[vertices][vertices] = { {0,0,3,0,0},
		 {0,0,10,4,0},
		 {3,10,0,2,6},
		 {0,4,2,0,1},
		 {0,0,6,1,0},
	 };
	 prim(g);
	 return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
