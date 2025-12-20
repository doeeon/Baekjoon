#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <utility>

using namespace std;

int Matching_Name_Id(string name, unordered_map<string, int>& name_id, vector<int>& parent, vector<int>& sz)
{
	if (name_id.find(name) == name_id.end())
	{
		int idx = name_id.size();
		name_id.emplace(name, idx);
		parent.push_back(idx);
		sz.push_back(1);
		return idx;
	}

	return name_id[name];
}

int Find(int x, vector<int>& parent)
{
	if (parent[x] == x) return x;
	return parent[x] = Find(parent[x], parent);
}

int Unite(int x, int y, vector<int>& parent, vector<int>& sz)
{
	x = Find(x, parent);
	y = Find(y, parent);

	if (x == y) return sz[x];
	if (sz[x] < sz[y]) swap(x, y);
	parent[y] = x;
	sz[x] += sz[y];
	return sz[x];
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

		string a_name, b_name;


		unordered_map<string, int> user_id;
		vector<int> parent;
		vector<int> sz;

		for (int i = 0; i < F; i++)
		{
			cin >> a_name >> b_name;
			int A_idx = Matching_Name_Id(a_name, user_id, parent, sz);
			int B_idx = Matching_Name_Id(b_name, user_id, parent, sz);

			cout << Unite(A_idx, B_idx, parent, sz) << '\n';
		}
	}

	return 0;
}