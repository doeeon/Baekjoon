#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main() {
	int K;
	cin >> K;

	string str;
	int num;
	queue<int> q;
	for (int i = 0; i < K; i++)
	{
		cin >> str;
		if (str == "push") // push
		{
			cin >> num;
			q.push(num);
		}
		else if (str == "pop") // pop
		{
			if (q.empty())
				cout << -1 << '\n';
			else
			{
				cout << q.front() << '\n';
				q.pop();
			}
		}
		else if (str == "size") // size
			cout << q.size() << '\n';
		else if (str == "empty") // empty
			cout << q.empty() << '\n';
		else if(str == "front")
		{
			if (q.empty())
				cout << -1 << '\n';
			else
				cout << q.front() << '\n';
		}
		else // back
		{
			if (q.empty())
				cout << -1 << '\n';
			else
				cout << q.back() << '\n';
		}
	}

	return 0;
}