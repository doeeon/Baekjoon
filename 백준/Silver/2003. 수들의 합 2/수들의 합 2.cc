#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	vector<int> num(N);
	for (int i = 0; i < N; i++)
		cin >> num[i];

	int left = 0;
	int right = 0;
	int sum = num[0];
	int count = 0;

	while (right < N && left <= right)
	{
		if (sum < M)
		{
			right++;
			if (right >= N) break;
			sum += num[right];
		}
		else if (sum > M)
		{
			sum -= num[left];
			left++;
			if (left > right)
			{
				right++;
				if (right >= N) break;
				sum += num[right];
			}
		}
		else
		{
			count++;
			right++;
			if (right >= N) break;
			sum += num[right];
		}
	}

	cout << count;
	return 0;
}