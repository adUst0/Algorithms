#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

const int MAX = 1000;

struct Edge {
	int from, to, weight;
	bool operator<(const Edge& o) const {
		return weight > o.weight;
		// priority_queue -> from max_heap to min_heap
	}	
};

int prim(vector<Edge> *g, int n, int start = 0) {
	priority_queue<Edge> pq;

	for (int i = 0; i < g[start].size(); i++)
		pq.push(g[start][i]);

	bool used[MAX];
	memset(used, 0, sizeof(used));
	used[start] = true;

	int res = 0;

	while (!pq.empty()) {
		int from = pq.top().from,
			to = pq.top().to,
			weight = pq.top().weight;
		pq.pop();

		if (!used[to]) {

			used[to] = true;
			res += weight;

			printf("%d %d %d\n", from+1, to+1, weight);

			for (int i = 0; i < g[to].size(); i++)
				if (!used[g[to][i].to])
					pq.push(g[to][i]);
		}
	}

	return res;
}

int main() {
	int N, M;
	vector<Edge> graph[MAX]; // graph[from] -> vector of Edges: from->to->weight, where 'to' is neighbor of 'from'.

	scanf("%d %d", &N, &M);

	int from, to, weight;
	for( int i = 0; i < M; i++ ) {
		scanf("%d %d %d", &from, &to, &weight);
		graph[from-1].push_back( {from-1, to-1, weight} );
		graph[to-1].push_back( {to-1, from-1, weight} );
	}

	printf("%d\n", prim(graph, N, 0));

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