#include <iostream>
#include <string>

using namespace std;

int main() {
	int N;
	cin >> N;
	int answer = 666;

	int cnt = 0;
	while (cnt <= N) {
		if (to_string(answer).find("666") != string::npos)
			cnt++;

		if (cnt == N)
			break;
		answer++;
	}

	cout << answer << endl;
	return 0;
}