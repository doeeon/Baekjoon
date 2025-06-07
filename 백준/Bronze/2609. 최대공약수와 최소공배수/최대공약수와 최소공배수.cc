#include <iostream>
#include <cmath>
using namespace std;

int GCD(int a, int b)
{
	int r;
	while (b > 0)
	{
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main() {
	int a, b;
	cin >> a >> b;

	int gcd = GCD(a, b);
	int lcm = a * b / gcd;

	cout << gcd << endl << lcm;
	return 0;
}