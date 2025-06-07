#include <iostream>

using namespace std;

int main() {
	int N;
	cin >> N;

	// 1 6 12 18 24 ...
	int sum = 1;
	int idx;
	for (idx = 1; sum < N; idx++)
		sum += 6 * idx;

	cout << idx;

	return 0;
}