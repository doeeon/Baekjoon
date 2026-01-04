#include <iostream>
#include <vector>
#include <utility>
#include <unordered_set>

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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	vector<int> truth;
	vector<vector<int>> party;

	vector<int> parent(N + 1);
	vector<int> sz(N + 1, 1);
	for (int i = 0; i <= N; i++)
		parent[i] = i;
	
	int input;
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> input;
		truth.push_back(input);
		Unite(0, input, parent, sz); // parent[input] == parent[0] 이면 진실을 아는 사람
	}

	int m;
	int input2;
	for (int i = 0; i < M; i++)
	{
		cin >> m;
		party.push_back(vector<int>());
		for (int j = 0; j < m; j++)
		{
			cin >> input;
			party.back().push_back(input);
			if (j > 0)
				Unite(input2, input, parent, sz);
			input2 = input;
		}
	}

	int answer = 0;
	for (int i = 0; i < party.size(); i++)
	{
		bool can_lie = true;
		for (int p : party[i])
			for (int tr : truth)
				if (Find(p, parent) == Find(tr, parent))
				{
					can_lie = false;
					break;
				}

		if (can_lie)
			answer++;
	}

	cout << answer;
	return 0;
}
