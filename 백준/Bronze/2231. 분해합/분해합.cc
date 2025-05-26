#include <iostream>

using namespace std;

int main() {
	int N;
	cin >> N;
    int answer = 0;
	for (int i = 1; i <= N; i++)
	{
		int sum = i;
		int tmp = i;
		while (tmp > 0)
		{
			sum += tmp % 10;
			tmp /= 10;
		}

		if (sum == N)
		{
			answer = i;
			break;
		}
	}
    
    cout << answer << endl;
	return 0;
}