#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
	int N;
	string str;
	cin >> N >> str;

	long long tmp = 1;
	long long answer = 0;
	const int mod = 1234567891;
	for (int i = 0; i < N; i++)
	{
		if(i > 0)
			tmp = (tmp * 31) % mod;
		answer += ((str[i] - 'a' + 1)*tmp) % mod;
		answer %= mod;
	}

	cout << answer;
	return 0;
}