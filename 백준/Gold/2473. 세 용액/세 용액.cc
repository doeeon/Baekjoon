#include <iostream>
#include <vector>
#include <algorithm>
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

	sort(liquid.begin(), liquid.end());
	
	vector<int> answer_idx(3, 0);

	if (liquid.front() > 0)
	{
		answer_idx[0] = 0;
		answer_idx[1] = 1;
		answer_idx[2] = 2;
	}
	else if (liquid.back() < 0)
	{
		answer_idx[0] = N - 3;
		answer_idx[1] = N - 2;
		answer_idx[2] = N - 1;
	}
	else if (liquid.size() == 3)
	{
		answer_idx[0] = 0;
		answer_idx[1] = 1;
		answer_idx[2] = 2;
	}
	else
	{
		int idx = 0;
		int left, right;
		long long min_sum = 3000000000;
		long long tmp_sum = 0;
		for (idx = 0; idx < N - 2; idx++)
		{
			left = idx + 1;
			right = N - 1;

			if (liquid[idx] > 0)
			{
				if (min_sum > abs(liquid[idx] + liquid[idx+1] + liquid[idx+2]))
				{
					answer_idx[0] = idx;
					answer_idx[1] = idx + 1;
					answer_idx[2] = idx + 2;;
				}

				break;
			}

			while (left < right)
			{
				tmp_sum = liquid[idx] + liquid[left] + liquid[right];

				if (min_sum > abs(tmp_sum))
				{
					min_sum = abs(tmp_sum);
					answer_idx[0] = idx;
					answer_idx[1] = left;
					answer_idx[2] = right;
				}

				if (tmp_sum > 0)
					right--;
				else if (tmp_sum < 0)
					left++;
				else
					break;
			}

			if (tmp_sum == 0)
				break;
		}
	}

	for (int i = 0; i < 3; i++)
		cout << liquid[answer_idx[i]] << ' ';

	return 0;
}