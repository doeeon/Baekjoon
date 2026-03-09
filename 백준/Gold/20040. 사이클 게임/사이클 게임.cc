#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int Find(int x, vector<int>& parent)
{
	if(parent[x] == x) return x;
	return parent[x] = Find(parent[x], parent);
}

bool Unite(int x, int y, vector<int>& parent, vector<int>& sz)
{
	x = Find(x, parent);
	y = Find(y, parent);
	
	if (x == y) return false;
	if (sz[x] < sz[y]) swap(x, y);
	parent[y] = x;
	sz[x] += sz[y];
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	vector<int> parent(N);
	vector<int> sz(N, 1);
	for (int i = 0; i < N; i++)
		parent[i] = i;

	int u, v;
	for (int m = 1; m <= M; m++)
	{
		cin >> u >> v;
		if (Unite(u, v, parent, sz) == false)
		{
			cout << m;
			return 0;
		}
	}

	cout << 0;
	return 0;
}