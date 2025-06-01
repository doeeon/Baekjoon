#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int answer;
	int n, m;
	cin >> n >> m;
	
	vector<int> num(n, 0);

	int tmp;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		num[i] = tmp;
	}

	tmp = 0;
	vector<int> sum(n, 0); // sum[x] = num[0]~num[x]까지의 누적합
	for (int i = 0; i < n; i++)
	{
		tmp += num[i];
		sum[i] = tmp;
	}

	int s, e;
	for (int i = 0; i < m; i++)
	{
		cin >> s >> e;
		cout << sum[e-1] - sum[s-1] + num[s-1] << '\n';
	}

	return 0;
}