#include <iostream>
#include <vector>

const long long INF = 1e18;

using namespace std;

struct Edge {
	int u;
	int v;
	int w;
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	vector<Edge> edges(M);
	for (int i = 0; i < M; i++)
		cin >> edges[i].u >> edges[i].v >> edges[i].w;

	vector<long long> dist(N + 1, INF);
	dist[1] = 0; // start

	for (int i = 1; i <= N - 1; i++)
		for (Edge e : edges)
			if (dist[e.u] != INF && dist[e.v] > dist[e.u] + e.w)
				dist[e.v] = dist[e.u] + e.w;


	bool HasNegativeCycle = false;
	for (Edge e : edges)
		if (dist[e.u] != INF && dist[e.v] > dist[e.u] + e.w)
		{
			HasNegativeCycle = true;
			break;
		}


	if (HasNegativeCycle)
		cout << -1;
	else
	{
		for (int i=2; i<dist.size(); i++)
		{
			if (dist[i] == INF)
				cout << -1 << '\n';
			else
				cout << dist[i] << '\n';
		}
	}

	return 0;
}