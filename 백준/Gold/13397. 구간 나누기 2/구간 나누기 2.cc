#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool IsPossible(int t, int M, vector<int>& num)
{
	int partition = 1;
	int max_n = 0;
	int min_n = 10001;
	for (int i = 0; i < num.size(); i++)
	{
		max_n = max(max_n, num[i]);
		min_n = min(min_n, num[i]);
		if (max_n - min_n > t)
		{
			partition++;
			max_n = num[i];
			min_n = num[i];
		}
	}

	if (partition <= M) // lower_bound
		return true;
	
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	vector<int> num(N);
	int max_num = 0;
	int min_num = 10001;
	for (int i = 0; i < N; i++)
	{
		cin >> num[i];
		max_num = max(max_num, num[i]);
		min_num = min(min_num, num[i]);
	}

	int left = 0;
	int right = max_num - min_num;
	// lower_bound
	while (left < right)
	{
		int mid = (left + right) / 2;
		if (IsPossible(mid, M, num))
			right = mid;
		else
			left = mid + 1;
	}

	cout << left;
	return 0;
}