#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

#define INF 200000000

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	vector<vector<int>> cost(N+1, vector<int>(3, 0));
	for (int i = 1; i <= N; i++)
		cin >> cost[i][0] >> cost[i][1] >> cost[i][2];

	vector<vector<int>> R_dp(N + 1, vector<int>(3, INF));
	R_dp[1][0] = cost[1][0];
	R_dp[2][1] = R_dp[1][0] + cost[2][1];
	R_dp[2][2] = R_dp[1][0] + cost[2][2];

	for (int i = 3; i < N; i++)
	{
		R_dp[i][0] = min(R_dp[i - 1][1], R_dp[i - 1][2]) + cost[i][0];
		R_dp[i][1] = min(R_dp[i - 1][0], R_dp[i - 1][2]) + cost[i][1];
		R_dp[i][2] = min(R_dp[i - 1][0], R_dp[i - 1][1]) + cost[i][2];
	}

	R_dp[N][1] = min(R_dp[N - 1][0], R_dp[N - 1][2]) + cost[N][1];
	R_dp[N][2] = min(R_dp[N - 1][0], R_dp[N - 1][1]) + cost[N][2];

	vector<vector<int>> G_dp(N + 1, vector<int>(3, INF));
	G_dp[1][1] = cost[1][1];
	G_dp[2][0] = G_dp[1][1] + cost[2][0];
	G_dp[2][2] = G_dp[1][1] + cost[2][2];

	for (int i = 3; i < N; i++)
	{
		G_dp[i][0] = min(G_dp[i - 1][1], G_dp[i - 1][2]) + cost[i][0];
		G_dp[i][1] = min(G_dp[i - 1][0], G_dp[i - 1][2]) + cost[i][1];
		G_dp[i][2] = min(G_dp[i - 1][0], G_dp[i - 1][1]) + cost[i][2];
	}

	G_dp[N][0] = min(G_dp[N - 1][1], G_dp[N - 1][2]) + cost[N][0];
	G_dp[N][2] = min(G_dp[N - 1][0], G_dp[N - 1][1]) + cost[N][2];

	vector<vector<int>> B_dp(N + 1, vector<int>(3, INF));
	B_dp[1][2] = cost[1][2];
	B_dp[2][0] = B_dp[1][2] + cost[2][0];
	B_dp[2][1] = B_dp[1][2] + cost[2][1];

	for (int i = 3; i < N; i++)
	{
		B_dp[i][0] = min(B_dp[i - 1][1], B_dp[i - 1][2]) + cost[i][0];
		B_dp[i][1] = min(B_dp[i - 1][0], B_dp[i - 1][2]) + cost[i][1];
		B_dp[i][2] = min(B_dp[i - 1][0], B_dp[i - 1][1]) + cost[i][2];
	}

	B_dp[N][0] = min(B_dp[N - 1][1], B_dp[N - 1][2]) + cost[N][0];
	B_dp[N][1] = min(B_dp[N - 1][0], B_dp[N - 1][2]) + cost[N][1];


	int R_min = min(min(R_dp[N][0], R_dp[N][1]), R_dp[N][2]);
	int G_min = min(min(G_dp[N][0], G_dp[N][1]), G_dp[N][2]);
	int B_min = min(min(B_dp[N][0], B_dp[N][1]), B_dp[N][2]);

	cout << min(min(R_min, G_min), B_min);
	return 0;
}