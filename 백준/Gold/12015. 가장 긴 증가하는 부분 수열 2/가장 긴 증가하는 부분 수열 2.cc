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
			if (arr[i] > LIS.back())
				LIS.push_back(arr[i]);
			else
				*lower_bound(LIS.begin(), LIS.end(), arr[i]) = arr[i];
		}
	}

	cout << LIS.size();
	return 0;
}