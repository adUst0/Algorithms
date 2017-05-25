#include <iostream>
using namespace std;
#define MAX 1001
#define INF 1000000000

struct Edge {
	int from, to, weight;
};

void BellmanFord(pair<int, int> *dist, int n, Edge *edges, int m, int s1) {

	for (int i = 0; i < n; i++) {
		dist[i].first = INF;
		dist[i].second = -1;
	}
	dist[s1].first = 0;

	for (int k = 1; k < n; k++)
		for (int i = 0; i < m; i++)
			if (dist[edges[i].to].first > dist[edges[i].from].first + edges[i].weight) {
				dist[edges[i].to].first = dist[edges[i].from].first + edges[i].weight;
				dist[edges[i].to].second = edges[i].from;
			}

	for (int i = 0; i < m; i++)
		if (dist[edges[i].to].first > dist[edges[i].from].first + edges[i].weight)
			throw std::invalid_argument("Cycle with negative length.\n");
}

void print(pair<int, int> *dist, int end) {
	if (dist[end].second == -1)
		return;
	print(dist, dist[end].second);
	printf("%d ", end + 1);
}
void printPath(pair<int, int> *dist, int start, int end) {
	printf("The shortest path from %d to %d is: ", start+1, end+1);
	printf("%d ", start+1 );
	print(dist, end);
	printf("\n");
}

int main() {

	int n, // #vertexes
		m; // #edges

	pair<int, int> dist[MAX];
	// dist[i].first -> distance to i in the shortest path
	// dist[i].second -> previous vertex in the shortest path

	Edge edges[MAX];

	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int from, to, weight;
		scanf("%d %d %d", &from, &to, &weight);
		edges[i] = {from-1, to-1, weight};
	}

	int start = 1;
	BellmanFord(dist, n, edges, m, start-1);

	return 0;
}

// test
// int end = 6
// printPath(dist, start-1, end-1);
// printf("Cost from %d to %d is: %d\n", start, end, dist[end-1].first);
// for (int i = 0; i < n; i++) {
// 	printf("Shortest path from %d to %d costs: %d\n", start, i+1, dist[i].first);
// }
/*
6 8
1 2 10
1 6 8
2 4 2
3 2 1
4 3 -2
5 2 -4
5 4 -1
6 5 1
*/