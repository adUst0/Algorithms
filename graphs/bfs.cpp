#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

void bfs(vector<int>* graph, int node) {
	queue<int> q; 
	q.push(node);

	bool visited[1001];
	memset(visited, 0, sizeof(visited));
	visited[node] = true;

	while(!q.empty()) {
		int current = q.front();
		q.pop();

		printf("%d ",current+1);

		for (int i = 0; i < graph[current].size(); i++)
			if (visited[graph[current][i]] == false) {
				q.push(graph[current][i]);
				visited[graph[current][i]] = true;
			}
	}
	printf("\n");
}


int main(){
	vector<int> g[1001];

	int n, m; scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int v, f;
		scanf("%d %d", &v, &f);
		g[v - 1].push_back(f - 1);
		g[f - 1].push_back(v - 1);
	}

	// 0 -> 1 node
	bfs(g, 0);

	return 0;
}
