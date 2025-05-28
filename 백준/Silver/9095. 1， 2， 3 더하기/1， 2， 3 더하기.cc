#include <iostream>

using namespace std;

int Operation(int num, int sum)
{
	int answer = 0;
	if (sum == num)
		answer++;

	else {
		for (int i = 1; i <= 3; i++)
			if (sum + i <= num)
				answer += Operation(num, sum + i);
	}

	return answer;
}


int main() {
	int T;
	cin >> T;

	int num;
	for (int i = 0; i < T; i++)
	{
		cin >> num;
		int answer = 0;
		answer = Operation(num, 0);

		cout << answer << endl;
	}

	return 0;
}