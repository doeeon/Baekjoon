#include <iostream>

using namespace std;

int Combi(int n, int k)
{
	if (k == 0 || k == n)
		return 1;

	return Combi(n - 1, k - 1) + Combi(n - 1, k);
}

int main() {
	int n, k;
	cin >> n >> k;

	cout << Combi(n, k);
		
	return 0;
}