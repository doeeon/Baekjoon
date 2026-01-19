#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	vector<int> honey(N+1);
	vector<int> prefix_sum(N+1);
	for (int i = 1; i <= N; i++)
	{
		cin >> honey[i];
		prefix_sum[i] += prefix_sum[i - 1] + honey[i];
	}

	int answer = 0;
	for (int b2 = 2; b2 <= N - 1; b2++)
	{
		answer = max(answer, (prefix_sum[N] - prefix_sum[1] - honey[b2]) + (prefix_sum[N] - prefix_sum[b2])); // 벌통이 N에 있는 경우
		answer = max(answer, prefix_sum[N - 1] - honey[b2] + prefix_sum[b2 - 1]); // 벌통이 1에 있는 경우
	}

	for (int i = 2; i < N; i++) //벌통이 중간에 있는 경우
	{	
		answer = max(answer, prefix_sum[N - 1] - prefix_sum[1] + honey[i]);
		//answer = max(answer, (prefix_sum[i]-prefix_sum[1]) + (prefix_sum[N-1]-prefix_sum[i-1]));	
	}

	cout << answer;
	return 0;
}