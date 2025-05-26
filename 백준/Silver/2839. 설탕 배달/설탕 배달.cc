#include <iostream>

using namespace std;

int main() {
	int N;
	cin >> N;
	int answer = -1;

	for (int i = 0; i <= N / 5; i++)
		if ((N - i * 5) % 3 == 0)
			answer = i + (N - i * 5) / 3;

	cout << answer << endl;
	return 0;
}