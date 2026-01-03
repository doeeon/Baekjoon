#include <iostream>
#include <vector>
#include <utility>

using namespace std; 

int Find(int x, vector<int>& parent)
{
	if (parent[x] == x) return x;
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

	vector<int> parent(N+1);
	vector<int> sz(N+1, 1);
	for (int i = 0; i < N+1; i++)
		parent[i] = i;

	int type, a, b;
	for (int i = 0; i < M; i++)
	{
		cin >> type >> a >> b;
		if (type == 0)
			Unite(a, b, parent, sz);
		else
		{
			if (Find(a, parent) == Find(b, parent))
				cout << "YES\n";
			else
				cout << "NO\n";
		}
	}
	return 0;
}