#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
	int N;
	string str;
	cin >> N >> str;

	long long tmp;
	long long answer = 0;
	for (int i = 0; i < N; i++)
		answer += ((str[i] - 'a' + 1)*(long long)pow(31,i)) % 1234567891;

	cout << answer;
	return 0;
}