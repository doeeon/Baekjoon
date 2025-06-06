#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <numeric>

using namespace std;

int main() {
	int n;
	cin >> n;

	if (n == 0)
		cout << 0;
	else {
		int tmp;
		vector<int> v(n, 0);
		for (int i = 0; i < n; i++)
		{
			cin >> tmp;
			v[i] = tmp;
		}

		sort(v.begin(), v.end());

		double sum = accumulate(v.begin() + round(n * 0.15), v.end() - round(n * 0.15), 0LL);
		cout << round(sum / (n - 2 * round(n * 0.15)));
	}
	return 0;
}