#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N;
	cin >> N;

	vector<bool> prime(1001, true);
	prime[0] = false;
	prime[1] = false;
	for (int i = 2; i <= 1000; i++)
		if (prime[i])
			for (int j = i * 2; j <= 1000; j += i)
				prime[j] = false;

	int answer = 0;
	int input;
	for (int i = 0; i < N; i++) {
		cin >> input;
		if (prime[input])
			answer++;
	}

	cout << answer;

	return 0;
}