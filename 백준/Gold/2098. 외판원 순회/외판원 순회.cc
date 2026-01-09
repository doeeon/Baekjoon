#include <iostream>
#include <vector>
#include <cmath>

#define INF 1e9
using namespace std;

int N;
vector<vector<int>> dp;
vector<vector<int>> W;

int DFS(int cur, int mask)
{
	if (mask == (1 << N) - 1) // 모든 도시를 방문한 경우
	{
		return W[cur][1]; // 시작 도시로 돌아오는 비용 반환
	}

	if (dp[cur][mask] != -1) // 이미 최소값이 계산된 경우
		return dp[cur][mask];

	// dp가 한 번도 기록되지 않은 경우
	dp[cur][mask] = INF;

	for (int n = 1; n <= N; n++) // 차례대로 도시 방문
	{
		int next = 1 << (n - 1); // 방문할 도시의 비트
		if (mask & next || W[cur][n] == INF) continue; // 이미 방문했거나, 길이 없는 경우
		int new_mask = mask | next; // n번 도시 방문 처리한 mask
		dp[cur][mask] = min(dp[cur][mask], W[cur][n] + DFS(n, new_mask)); // 최소값 갱신
	}

	return dp[cur][mask]; // 최소 비용값 return
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	W.resize(N + 1, vector<int>(N + 1));
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
		{
			cin >> W[i][j];
			if (W[i][j] == 0)
				W[i][j] = INF;
		}

	dp.resize(N + 1, vector<int>(1 << N, -1));
	// dp[][] == -1 : 아직 갱신안한 상태
	// dp[][] == INF : 갱신 시작, 최종 상태가 INF라면 불가능한 경로
	// else : dp[][] : 최솟값 기록된 상태

	int answer = DFS(1, 1<<0); // 시작도시 1번, 1번 방문한 상태로 시작
	cout << answer;
	return 0;
}