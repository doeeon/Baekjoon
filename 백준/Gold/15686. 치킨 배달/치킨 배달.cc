#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int Check_dist(vector<pair<int, int>>& house, vector<pair<int, int>>& chicken)
{
	int result = 0;
	for (int i = 0; i < house.size(); i++)
	{
		int dist = 1000000;
		for (int j = 0; j < chicken.size(); j++)
		{
			int tmp = abs(house[i].first - chicken[j].first) + abs(house[i].second - chicken[j].second);
			dist = min(dist, tmp);
		}
		result += dist;
	}

	return result;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int answer = 50 * 50 * 100;
	int N, M;
	cin >> N >> M;

	int a;
	vector<pair<int, int>> house;
	vector<pair<int, int>> chicken;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0;j < N; j++)
		{
			cin >> a;
			if (a == 1)
				house.push_back({ i, j });
			else if (a == 2)
				chicken.push_back({ i, j });

		}
	}

	vector<int> tmp(chicken.size(), 1);
	for (int i = 0; i < chicken.size()-M; i++)
		tmp[i] = 0;

	do
	{
		vector<pair<int, int>> target;
		for (int i = 0; i < tmp.size(); i++)
			if (tmp[i])
				target.push_back(chicken[i]);

		answer = min(answer, Check_dist(house, target));

	} while (next_permutation(tmp.begin(), tmp.end()));

	cout << answer;
	return 0;
}