#include <iostream>
#include <string>

using namespace std;

int main() {
	string str;

	cin >> str;

	long long sum = 0;
	int ans;
	for (int i = 0; i < 13; i++)
	{
		if (str[i] == '*')
		{
			ans = i;
			continue;
		}

		if (i % 2 == 0)
			sum += (str[i]-'0');
		else
			sum += 3 * (str[i]-'0');
	}

	if (ans % 2 == 0)
		ans = sum % 10 == 0 ? 0 : (10 - sum % 10);
	else
	{
		int arr[10] = { 0, 7, 4, 1, 8, 5, 2, 9, 6, 3 };
		ans = arr[sum % 10 == 0 ? 0 : (10 - sum % 10)];
	}

	cout << ans;
	return 0;
}