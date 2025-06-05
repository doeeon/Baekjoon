#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N;

	int n;
	vector<int> v(20000001, 0);
	for (int i = 0; i < N; i++)
	{
		cin >> n;
		v[n+10000000]++;
	}

	cin >> M;
	int m;
	for (int i = 0; i < M; i++)
	{
		cin >> m;
		cout << v[m+10000000] << ' ';
	}
	return 0;
}