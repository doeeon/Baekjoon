#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int BFS(int i, int N, vector<pair<int, int>>& map, vector<bool> visited)
{
	int cnt = 0;
	queue<int> q;
	q.push(i);
	visited[i] = true;

	int level = 0;
	while (!q.empty())
	{	
		level++;
		int size = q.size();
		for (int i = 0; i < size; i++)
		{
			int cur = q.front();
			for (int i = 0; i < map.size(); i++)
			{
				if (map[i].first == cur && !visited[map[i].second])
				{
					q.push(map[i].second);
					visited[map[i].second] = true;
					cnt += level;
				}
				else if (map[i].second == cur && !visited[map[i].first])
				{
					q.push(map[i].first);
					visited[map[i].first] = true;
					cnt += level;
				}
			}
			q.pop();
		}
	}

	return cnt;
}

int main() {
	int N, M;
	cin >> N >> M;

	int a, b;
	vector<pair<int, int>> map;
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		map.push_back({ a, b });
	}

	vector<int> answer(N + 1, 10000);
	vector<bool> visited(N+1, 0);
	for (int i = 1; i <= N; i++)
		answer[i] = (BFS(i, N, map, visited));

	cout << min_element(answer.begin(), answer.end()) - answer.begin();
	return 0;
}