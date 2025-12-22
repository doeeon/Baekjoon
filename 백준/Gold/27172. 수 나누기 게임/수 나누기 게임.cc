#include <iostream>
#include <vector>
#include <cmath>

#define INF 1000001

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	vector<int> num(N);
	vector<bool> exist(INF, false);
	vector<int> score(INF, 0);

	int maximum = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> num[i];
		maximum = max(maximum, num[i]);
		exist[num[i]] = true;
	}

	for (int x = 1; x <= maximum; x++)
	{
		if (!exist[x])
			continue;

		for (int k = x * 2; k <= maximum; k += x)
			if (exist[k])
			{
				score[x]++;
				score[k]--;
			}
	}

	for (int n : num)
		cout << score[n] << ' ';

	return 0;
}