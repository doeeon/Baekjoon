#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	vector<int> arr(N, 0);
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	vector<int> LIS;
	vector<int> parent(N, -1); // arr[i]가 LIS에 포함될때, 그 바로 이전 LIS원소의 arr 인덱스
	vector<int> pos(N, -1); // pos[n] : LIS의 길이가 n+1일 때, LIS 배열의 마지막 원소의 arr 인덱스
	for (int i = 0; i < N; i++)
	{
		if (LIS.empty())
		{
			LIS.push_back(arr[i]);
			pos[0] = i;
			parent[i] = -1;
		}
		else
		{
			int idx = lower_bound(LIS.begin(), LIS.end(), arr[i]) - LIS.begin();
			if (idx == 0)
			{
				pos[0] = i;
				parent[i] = -1;
				LIS[idx] = arr[i];
			}
			else if (idx >= LIS.size())
			{
				pos[idx] = i;
				parent[i] = pos[idx - 1];
				LIS.push_back(arr[i]);
			}
			else
			{
				pos[idx] = i;
				parent[i] = pos[idx - 1];
				LIS[idx] = arr[i];
			}
		}
	}

	vector<int> answer;
	int idx = pos[LIS.size() - 1];
	while (idx > -1)
	{
		answer.push_back(arr[idx]);
		idx = parent[idx];
	}

	reverse(answer.begin(), answer.end());

	cout << LIS.size() << '\n';
	for (auto n : answer)
		cout << n << ' ';
	return 0;
}