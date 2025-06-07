#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	
	string str;
	string r_str;
	while (1)
	{
		cin >> n;
		if (n == 0)
			break;

		str = to_string(n);
		r_str = str;
		reverse(r_str.begin(), r_str.end());

		if (str == r_str)
			cout << "yes\n";
		else
			cout << "no\n";
	}
	
	return 0;
}