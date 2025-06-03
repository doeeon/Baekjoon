#include <iostream>
#include <set>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	multiset<int> ms;
	int num;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		if (num > 0)
			ms.insert(num);
		else
		{
			if (ms.empty())
				cout << '0' << '\n';
			else {
				cout << *ms.begin() << '\n';
				ms.erase(ms.begin());
			}
		}
	}
	return 0;
}