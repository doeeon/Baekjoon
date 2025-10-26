#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;
	vector<vector<int>> dp_min(2, vector<int>(3, 0));
	vector<vector<int>> dp_max(2, vector<int>(3, 0));
	//dp[0][] : i-1번째까지 내려왔을 떄 점수 
	//dp[1][] : i번째까지 내려왔을 때 점수

	int num[3] = { 0 };
	cin >> num[0] >> num[1] >> num[2];
	for (int i = 0; i < 3; i++)
	{
		dp_min[0][i] = num[i];
		dp_max[0][i] = num[i];
	}
	int prev = 1;
	int curr = 0; // index

	for (int i = 1; i < N; i++)
	{
		cin >> num[0] >> num[1] >> num[2];

		
		prev ^= 1;
		curr ^= 1;

		dp_min[curr][0] = min(dp_min[prev][0], dp_min[prev][1]) + num[0];
		dp_min[curr][1] = min(dp_min[prev][0], min(dp_min[prev][1], dp_min[prev][2])) + num[1];
		dp_min[curr][2] = min(dp_min[prev][1], dp_min[prev][2]) + num[2];

		dp_max[curr][0] = max(dp_max[prev][0], dp_max[prev][1]) + num[0];
		dp_max[curr][1] = max(dp_max[prev][0], max(dp_max[prev][1], dp_max[prev][2])) + num[1];
		dp_max[curr][2] = max(dp_max[prev][1], dp_max[prev][2]) + num[2];
	}

	cout << max(dp_max[curr][0], max(dp_max[curr][1], dp_max[curr][2])) << ' ';
	cout << min(dp_min[curr][0], min(dp_min[curr][1], dp_min[curr][2]));
}