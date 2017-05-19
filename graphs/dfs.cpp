#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<int>* graph, int node, bool* visited) {
	printf("%d ", node + 1);
	visited[node] = true;

	for (int i = 0; i < graph[node].size(); i++)
		if (visited[graph[node][i]] == false)
			dfs(graph, graph[node][i], visited);
}


int main(){
	vector<int> g[1001];
	bool visited[1001];
	for (int i = 0; i < 1001; i++) 
		 visited[i] = 0;

	int n, m; scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int v, f;
		scanf("%d %d", &v, &f);
		g[v - 1].push_back(f - 1);
		g[f - 1].push_back(v - 1);
	}

	// 0 -> 1 node
	dfs(g, 0, visited);
	printf("\n");

	return 0;
}
