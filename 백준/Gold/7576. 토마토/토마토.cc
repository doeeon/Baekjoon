#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int BFS(int N, int M, queue <pair<int, int>>& q, vector<vector<int>>& map)
{
	int cnt = 0;
	int dx[4] = { 1, -1, 0, 0 };
	int dy[4] = { 0, 0, 1, -1 };
	vector<vector<bool>> visited(N, vector<bool>(M, false));

	while (!q.empty())
	{
		int size = q.size();
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				int nx = q.front().first + dx[j];
				int ny = q.front().second + dy[j];

				if (nx >= 0 && nx < M && ny >= 0 && ny < N && !visited[ny][nx] && map[ny][nx] == 0)
				{
					q.push({ nx, ny });
					map[ny][nx] = 1;
					visited[ny][nx] = true;
				}
			}
			q.pop();
		}
		cnt++;
	}

	return cnt-1;
}

int main() {
	int answer = 0;
	int M, N;
	cin >> M >> N;

	int num;
	bool already = true; // 이미 모든 토마토가 익은 상태인지 check
	bool possible = true; //토마토가 모두 익을 수 있는 지 check
	vector<vector<int>> box(N, vector<int>(M, 0));
	queue<pair<int, int>> q;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> num;
			box[i][j] = num;
			if (already && num == 0)
				already = false; // 이미 모든 토마토가 익은 상태면 모두 1 or -1
			if (num == 1) // 익은 토마토는 queue에 push
				q.push({ j, i });
		}
	}

	if (already)
		cout << 0;
	else
	{
		answer = BFS(N, M, q, box);

		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				if (box[i][j] == 0) { // 모두 안 익은 상태면
					possible = false; 
					break;
				}
		if (!possible)
			cout << -1;
		else
			cout << answer;
	}
	return 0;
}