#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void BFS(int s, int N, vector<vector<int>>& map, vector<vector<int>>& answer)
{
	vector<bool> visited(N, false);
	queue<int> q;
	q.push(s); //visited 표시 X, 이후 while문에서 s 방문 가능하면 visited will be true

	while (!q.empty())
	{
		int cur = q.front();
		for (int i = 0; i < N; i++)
		{
			if (map[cur][i] == 1 && !visited[i])
			{
				q.push(i);
				visited[i] = true;
				answer[s][i] = 1;
			}
		}
		q.pop();
	}

	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	vector<vector<int>> map(N, vector<int>(N, 0));
	vector<vector<int>> answer(N, vector<int>(N, 0));
	int n;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			cin >> n;
			map[i][j] = n;
		}
	
	for (int i = 0; i < N; i++)
		BFS(i, N, map, answer);

	for (auto a : answer)
	{
		for (auto b : a)
			cout << b << ' ';
		cout << '\n';
	}
	return 0;
}