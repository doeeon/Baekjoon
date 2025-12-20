#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>
#include <unordered_map>

using namespace std;

string Find(string x, unordered_map<string, string>& parent)
{
	if (parent[x] == x) return x;
	return parent[x] = Find(parent[x], parent);
}

bool Unite(string x, string y, unordered_map<string, string>& parent, unordered_map<string, int>& sz)
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
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	for (int t = 0; t < T; t++)
	{
		int F;
		cin >> F;

		string A_ID, B_ID;

		unordered_map<string, string> parent;
		unordered_map<string, int> sz;

		for (int i = 0; i < F; i++)
		{
			cin >> A_ID >> B_ID;
			if (parent.find(A_ID) == parent.end())
			{
				parent.emplace(A_ID, A_ID);
				sz.emplace(A_ID, 1);
			}

			if (parent.find(B_ID) == parent.end())
			{
				parent.emplace(B_ID, B_ID);
				sz.emplace(B_ID, 1);
			}

			Unite(A_ID, B_ID, parent, sz);
			cout << sz[Find(A_ID, parent)] << '\n';
		}
	}

	return 0;
}