#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// BFS 불가능 -> 가는 경로에 따라 방문한 알파벳이 다 다르기 때문에 불가능
// DFS & Backtracking으로 쭉 가다가 안되면 pruning 해야함.

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

void DFS(int y, int x, int R, int C, vector<vector<char>>& map, vector<bool>& vis_alpha, int cnt, int& answer)
{
	answer = max(answer, cnt);
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny >= 0 && ny < R && nx >= 0 && nx < C && !vis_alpha[map[ny][nx] - 'A'])
		{
			cnt++;
			vis_alpha[map[ny][nx] - 'A'] = true;
			DFS(ny, nx, R, C, map, vis_alpha, cnt, answer);
			cnt--;
			vis_alpha[map[ny][nx] - 'A'] = false;
		}
	}

}

int main()
{
	int R, C;
	cin >> R >> C;
	
	vector<vector<char>> map(R, vector<char>(C, 0));

	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			cin >> map[i][j];

	vector<bool> vis_alpha(26, false);
	int answer = 0;

	vis_alpha[map[0][0] - 'A'] = true;
	DFS(0, 0, R, C, map, vis_alpha, 1, answer);
	cout << answer;
	return 0;
}