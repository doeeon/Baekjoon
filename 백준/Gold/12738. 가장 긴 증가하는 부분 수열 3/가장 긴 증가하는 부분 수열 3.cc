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
		cin >> arr[i];

	vector<int> LIS;
	for (int i = 0; i < N; i++)
	{
		if (LIS.empty())
			LIS.push_back(arr[i]);
		else
		{
			int idx = lower_bound(LIS.begin(), LIS.end(), arr[i]) - LIS.begin();
			if (idx >= LIS.size())
				LIS.push_back(arr[i]);
			else
				LIS[idx] = arr[i];
		}
	}


	cout << LIS.size() << '\n';
	return 0;
}