#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int M, N;
	cin >> M >> N;

	vector<bool> prime(N+1, true);
	prime[0] = false;
	prime[1] = false;
	for (int i = 0; i < N+1; i++)
		if (prime[i])
			for (int j = i * 2; j < N + 1; j += i)
				prime[j] = false;

	for (int i = M; i <= N; i++)
		if (prime[i])
			cout << i << '\n';

	return 0;
}