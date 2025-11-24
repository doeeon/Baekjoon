#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <unordered_map>

using namespace std;

int Find(int X, vector<int>& parent)
{
	if (parent[X] == X)
		return X;
	else 
		return parent[X] = Find(parent[X], parent);
}

void Merge(int X, int Y, vector<int>& parent)
{
	X = Find(X, parent);
	Y = Find(Y, parent);
	if (X == Y)
		return;
	parent[Y] = X;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M, K;
	cin >> N >> M >> K;

	vector<int> Children(N+1, 0);
	vector<int> Parent(N+1);
	for (int i = 1; i <= N; i++)
	{
		cin >> Children[i];
		Parent[i] = i;
	}

	int x, y;
	for (int i = 0; i < M; i++)
	{
		cin >> x >> y;
		Merge(x, y, Parent);
		
	}

	unordered_map<int, pair<int, int>> group;
	for (int i = 1; i <= N; i++)
	{
		int p = Find(i, Parent);
		group[p].first++;
		group[p].second += Children[i];
	}

	//DP
	vector<int> dp(K, 0);
	for (auto iter = group.begin(); iter != group.end(); iter++)
	{
		for (int j = K - 1; j >= iter->second.first; j--)
		{
			dp[j] = max(dp[j], dp[j - iter->second.first] + iter->second.second);
		}
	}

	cout << *max_element(dp.begin(), dp.end());
	return 0;
}