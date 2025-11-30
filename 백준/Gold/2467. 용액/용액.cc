#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	vector<int> liquid(N, 0);
	for (int i = 0; i < N; i++)
		cin >> liquid[i];

	vector<int> answer = { 1000000000, 1000000000 };

	if (liquid[0] > 0)
	{
		answer[0] = liquid[0];
		answer[1] = liquid[1];
	}
	else if (liquid[N - 1] < 0)
	{
		answer[0] = liquid[N - 2];
		answer[1] = liquid[N - 1];
	}
	else
	{
		int left = -1, right = -1;
		for (int i = 0; i < N; i++)
			if (liquid[i] > 0)
			{
				left = i - 1;
				right = i;
				break;
			}

		if (left > 0 && abs(liquid[0] + liquid[1]) < liquid[right])
		{
			answer[0] = liquid[left - 1];
			answer[1] = liquid[left];
		}
		else if (right < N-1 && (liquid[N - 2] + liquid[N - 1]) < abs(liquid[left]))
		{
			answer[0] = liquid[right];
			answer[1] = liquid[right + 1];
		}

		while (left >= 0 && right < N)
		{
			if (liquid[left] + liquid[right] == 0)
			{
				answer[0] = liquid[left];
				answer[1] = liquid[right];
				break;
			}

			if (abs(answer[0] + answer[1]) > abs(liquid[left] + liquid[right]))
			{
				answer[0] = liquid[left];
				answer[1] = liquid[right];
			}

			if (liquid[left] + liquid[right] > 0)
				left--;
			else
				right++;
		}
	}

	cout << answer[0] << ' ' << answer[1];
	return 0;
}