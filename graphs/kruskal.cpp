#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX = 1000;

struct Edge {
	int from, to, weight;
	bool operator<(const Edge& o) const {
		return weight < o.weight;
	}	
};

int findParent(int *parent, int vertex) {
	if (parent[vertex] == vertex)
		return vertex;
	// Path compression
	return parent[vertex] = findParent(parent, parent[vertex]);
}

int kruskal(vector<Edge>& edges, int n) {
	sort(edges.begin(), edges.end());

	int res = 0, i = 0, vertexes = 0, parent[MAX];

	for (int i = 0; i < n; i++)
		parent[i] = i;

	while (vertexes < n - 1) {
		int u = findParent(parent, edges[i].from),
			v = findParent(parent, edges[i].to),
			w = edges[i].weight;

		if (u != v) {
			vertexes++;
			parent[u] = v;

			printf("%d %d %d\n", edges[i].from+1, edges[i].to+1, w);
			res += w;
		}

		i++;
	}

	return res;
}

int main() {

	int N, M;
	vector<Edge> edges;

	scanf("%d %d", &N, &M);

	for (int i = 0; i < M; i++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		edges.push_back( {u-1, v-1, w} );
	}

	printf("%d\n", kruskal(edges, N));

	return 0;
}

/*
9 18
1 2 22
1 3 9
1 4 12
2 8 34
2 6 36
2 3 35
3 6 42
3 5 65
3 4 4
4 5 33
4 9 30
5 6 18
5 7 23
6 8 24
6 7 39
7 8 25
7 9 21
8 9 19
*/