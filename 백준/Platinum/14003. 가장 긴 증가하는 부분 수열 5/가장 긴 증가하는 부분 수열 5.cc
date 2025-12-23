#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	vector<int> arr(N);

	vector<int> LIS;
	vector<int> pos(N + 1, -1); // pos[n] : LIS의 길이가 n일때, LIS의 마지막 원소에 대응되는 arr의 인덱스
	vector<int> parent(N); // parent[n] : LIS에서 arr[n] 전에 오는 원소에 대응되는 arr의 인덱스
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		parent[i] = i;
	}

	for (int i = 0; i < N; i++)
	{
		if (LIS.empty())
		{
			pos[1] = i;
			parent[i] = i; // start node
			LIS.push_back(arr[i]);
		}
		else
		{
			int idx = lower_bound(LIS.begin(), LIS.end(), arr[i]) - LIS.begin();
			if (idx == 0)
			{
				pos[1] = i;
				parent[i] = i;
				LIS[idx] = arr[i];
			}
			else if (idx == LIS.size())
			{
				pos[idx + 1] = i;
				parent[i] = pos[idx];
				LIS.push_back(arr[i]);
			}
			else
			{
				pos[idx + 1] = i;
				parent[i] = pos[idx];
				LIS[idx] = arr[i];
			}
		}
	}

	vector<int> answer;
	int a_idx = pos[LIS.size()];
	while (parent[a_idx] != a_idx)
	{
		answer.push_back(arr[a_idx]);
		a_idx = parent[a_idx];
	}
	answer.push_back(arr[a_idx]);
	reverse(answer.begin(), answer.end());

	cout << LIS.size() << '\n';
	for (int n : answer)
		cout << n << ' ';
	
	return 0;
}