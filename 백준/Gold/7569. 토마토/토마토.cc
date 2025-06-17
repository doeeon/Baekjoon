#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int BFS(int H, int N, int M, queue <vector<int>>& q, vector<vector<vector<int>>>& map)
{
	int cnt = 0;
	int dz[6] = { 0, 0, 0, 0, 1, -1 };
	int dx[6] = { 1, -1, 0, 0, 0, 0 };
	int dy[6] = { 0, 0, 1, -1, 0, 0 };
	vector<vector<vector<bool>>> visited(H, vector<vector<bool>>(N, vector<bool>(M, false)));

	while (!q.empty())
	{
		int size = q.size();
		for (int s = 0; s < size; s++)
		{
			for (int j = 0; j < 6; j++)
			{
				int nx = q.front()[0] + dx[j];
				int ny = q.front()[1] + dy[j];
				int nz = q.front()[2] + dz[j];

				if (nx >= 0 && nx < M && ny >= 0 && ny < N && nz>=0 && nz<H && !visited[nz][ny][nx] && map[nz][ny][nx] == 0)
				{
					q.push({ nx, ny, nz});
					map[nz][ny][nx] = 1;
					visited[nz][ny][nx] = true;
				}
			}
			q.pop();
		}
		cnt++;
	}

	return cnt - 1;
}

int main() {
	int answer = 0;
	int M, N, H;
	cin >> M >> N >> H;

	int num;
	bool already = true; // 이미 모든 토마토가 익은 상태인지 check
	bool possible = true; //토마토가 모두 익을 수 있는 지 check
	vector<vector<vector<int>>> box(H, vector<vector<int>> (N, vector<int>(M, 0)));
	queue<vector<int>> q;
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < M; k++)
			{
				cin >> num;
				box[i][j][k] = num;
				if (already && num == 0)
					already = false; // 이미 모든 토마토가 익은 상태면 모두 1 or -1
				if (num == 1) // 익은 토마토는 queue에 push
					q.push({ k, j, i }); // x y z
			}
		}
	}

	if (already)
		cout << 0;
	else
	{
		answer = BFS(H, N, M, q, box);

		for (int i = 0; i < H; i++)
			for (int j = 0; j < N; j++)
				for (int k = 0; k < M; k++)
				if (box[i][j][k] == 0) { // 모두 안 익은 상태면
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