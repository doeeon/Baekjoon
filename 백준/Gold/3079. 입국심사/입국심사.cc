#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool Interview(long long mid, long long M, vector<long long>& time)
{
	long long result = 0;
	for (int t : time)
	{
		result += mid / t;
		if (result >= M)
			return true;
	}

	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	long long N, M;
	cin >> N >> M;

	long long max_interview = 0;
	vector<long long> interview_time(N);
	for (int i = 0; i < N; i++)
	{
		cin >> interview_time[i];
		max_interview = max(max_interview, interview_time[i]);
	}

	long long left = 1;
	long long right = max_interview * M;
	while (left < right) // lower_bound
	{
		long long mid = (left + right) / 2;
		if (Interview(mid, M, interview_time))
			right = mid;
		else
			left = mid + 1;
	}

	cout << left;
	return 0;
}