#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	int num;
	double sum = 0;
	int n_max = -4000;
	int n_min = 4000;
	vector<int> cnt(8001, 0);
	vector<int> arr;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		arr.push_back(num);
		sum += num;
		cnt[num + 4000]++;
		n_max = max(n_max, num);
		n_min = min(n_min, num);
	}

	sort(arr.begin(), arr.end());
	
	int mode = 0;
	int mode_cnt = 1;
	for (int i = 1; i < cnt.size(); i++)
	{
		if (cnt[i] > cnt[mode])
		{
			mode = i;
			mode_cnt = 1;
		}
		else if (cnt[i] == cnt[mode] && mode_cnt < 2)
		{
			mode = i;
			mode_cnt = 2;
		}
	}
	
	int avg = round(sum / N);

	cout << avg << '\n';
	cout << arr[N / 2] << '\n';
	cout << mode - 4000 << '\n';
	cout << n_max - n_min;

	return 0;
}
