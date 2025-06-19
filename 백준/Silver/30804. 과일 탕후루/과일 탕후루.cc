#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>

using namespace std;

int main() {
	int N;
	cin >> N;

	int num;
	vector<int> fruits(N, 0);
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		fruits[i] = num;
	}

	int ans = 0;
	int s = 0;
	int e = 0;
	unordered_map<int, int> m;
	for (e = 0; e < N; e++)
	{
		m[fruits[e]]++;

		while (m.size() > 2)
		{
			m[fruits[s]]--;
			if (m[fruits[s]] == 0)
				m.erase(fruits[s]);
			s++;
		}

		ans = max(ans, e - s + 1);
	}

	cout << ans;
	return 0;
}