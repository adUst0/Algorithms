#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

const int MAX = 100;

struct Node {
	int to, weight;
	Node(int t = 0, int w = 0) : to(t), weight(w) {}
	bool operator<(const Node& other) const {
		if (weight == other.weight)
			return to < other.to;
		return weight > other.weight;
	}
};

int N, M, dist[MAX];
vector<Node> graph[MAX];
bool used[MAX];

void dijkstra(int start) {
	priority_queue<Node> q;
	q.push(Node(start, 0));
	dist[start] = 0;

	while(!q.empty()) {
		int u = q.top().to;
		q.pop();

		if (used[u] == false) {
			used[u] = true;

			for (int i = 0; i < graph[u].size(); i++) {
				int v = graph[u][i].to, w = graph[u][i].weight;

				if (!used[v] && dist[u] + w < dist[v]) {
					dist[v] = dist[u] + w;
					q.push(Node(v, dist[v]));
				}
			}
		}
	}
}

int main() {

	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		graph[u-1].push_back(Node(v-1, w));
		graph[v-1].push_back(Node(u-1, w));
	}

	memset(dist, 63, sizeof(dist));
	int start;
	scanf("%d", &start);
	dijkstra(start-1);
	for (int i = 0; i < N; i++) {
		cout << dist[i] << " ";
	}
	printf("\n");

	return 0;
}