#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<long long> P(101, 0);
	P[1] = 1;
	P[2] = 1;
	P[3] = 1;
	P[4] = 2;
	P[5] = 2;

	for (int i = 6; i <= 100; i++)
		P[i] = P[i - 5] + P[i - 1];

	int n;
	cin >> n;
	
	int input;
	for (int i = 0; i < n; i++)
	{
		cin >> input;
		cout << P[input] << '\n';
	}

	return 0;
}