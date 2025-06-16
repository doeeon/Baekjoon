#include <iostream>
#include <set>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;

	for (int t = 0; t < T; t++)
	{
		int N;
		cin >> N;

		multiset<int> ms;
		char c;
		int num;
		for (int i = 0; i < N; i++)
		{
			cin >> c >> num;
			if (c == 'I')
				ms.insert(num);
			
			else if (c == 'D' && ms.size() > 0)
			{
				if (num == 1)
					ms.erase(--ms.end());
				else
					ms.erase(ms.begin());
			}
		}

		if (ms.size() == 0)
			cout << "EMPTY\n";
		else
			cout << *(--ms.end()) << ' ' << *ms.begin() << '\n';
	}

	return 0;
}