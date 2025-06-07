#include <iostream>
#include <string>

using namespace std;

int main() {
	int N;
	cin >> N;

	int answer;
	answer = (N / 5) + (N / 25) + (N/125);
	// 25의 배수에는 5가 2개씩 들어있으므로 한 번 더 더해야 한다.
	// 125의 배수에는 5가 3개씩 들어있으므로 한 번 더 더해야 한다.
	cout << answer;
	return 0;
}