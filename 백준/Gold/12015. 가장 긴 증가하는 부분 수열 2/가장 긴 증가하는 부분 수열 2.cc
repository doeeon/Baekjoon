#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int BinarySearch(int num, vector<int>& v)
{
	int left = 0;
	int right = v.size() - 1;
	while (left < right)
	{
		int mid = (left + right) / 2;

		if (num <= v[mid])
			right = mid;
		else
			left = mid + 1;
	}

	return left;
}

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
				LIS[BinarySearch(arr[i], LIS)] = arr[i];
		}
	}

	cout << LIS.size();
	return 0;
}