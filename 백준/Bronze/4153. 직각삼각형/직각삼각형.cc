#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int a, b, c;

	while (1)
	{
		cin >> a >> b >> c;
		if (a == 0 && b == 0 && c == 0)
			break;

		if (a * a + b * b + c * c == 2 * max(max(a, b), c) * max(max(a, b), c))
			cout << "right\n";
		else
			cout << "wrong\n";
	}

	return 0;
}