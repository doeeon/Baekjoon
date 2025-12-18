#include <iostream>
#include <vector>

using namespace std;

vector<int> GeneratePrime(int N)
{
	vector<int> result;
	vector<bool> IsPrime(N + 1, true);
	for (int i = 2; i <= N; i++)
	{
		if (IsPrime[i])
			result.push_back(i);
		for (int j = i * 2; j <= N; j += i)
			IsPrime[j] = false;
	}

	return result;
}

int main()
{
	int N;
	cin >> N;

	vector<int> Prime = GeneratePrime(N);
	
	int answer = 0;
	if (Prime.size() > 0)
	{
		int left = 0;
		int right = 0;
		int sum = Prime[0];
		while (left <= right)
		{
			if (sum < N)
			{
				right++;
				if (right >= Prime.size())
					break;
				sum += Prime[right];
			}
			else
			{
				if (sum == N)
					answer++;

				sum -= Prime[left];
				left++;
				if (left >= Prime.size())
					break;
			}
		}
	}
	cout << answer;

	return 0;
}