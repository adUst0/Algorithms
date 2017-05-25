#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 1001;

void Floyd(int dist[MAX][MAX], int prev[MAX][MAX], int n) {
	for (int i = 0; i < n; i++)
		dist[i][i] = 0;

	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (dist[i][j] > dist[i][k] + dist[k][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
					prev[i][j] = k;
				}

	for (int i = 0; i < n; i++)
		if (dist[i][i] < 0)
			throw std::invalid_argument("Cycle with negative length.\n");
}

void print(int prev[MAX][MAX], int start, int end) {
	if (prev[start][end] == -1)
		return;
	print(prev, start, prev[start][end]);
	printf("%d ", end + 1);
}
void printPath(int prev[MAX][MAX], int start, int end) {
	printf("The shortest path from %d to %d is: ", start+1, end+1);
	printf("%d ", start+1 );
	print(prev, start, end);
	printf("\n");
}

int main() {

	int n, // #vertexes
		m, // #edges
		dist[MAX][MAX], // min distance in the shortest path from i to j
		prev[MAX][MAX]; // previous vertex in the shortest path from i to j
	scanf("%d %d", &n, &m);

	memset(prev, -1, sizeof(prev));
	memset(dist, 63, sizeof(dist)); // INF

	for (int i = 0; i < m; i++) {
		int from, to, weight;
		scanf("%d %d %d", &from, &to, &weight);

		if (dist[from - 1][to - 1] > weight) {
			dist[from - 1][to - 1] = weight;
			prev[from - 1][to - 1] = from - 1;
		}
	}

	Floyd(dist, prev, n);

	return 0;
}

// test
// int start = 3, end = 1;
// printPath(prev, start - 1, end - 1);
// printf("Cost from %d to %d is: %d\n", start, end, dist[start - 1][end - 1]);
/*
4 5
1 3 3
2 1 2
3 4 1
3 2 7
4 1 6
*/