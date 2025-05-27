#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main() {
	int n;
	cin >> n;
	cin.ignore();
	deque<int> dq; 
	string str;
	for (int i = 0; i < n; i++)
	{
		getline(cin, str);
		if (str.find("push_back") != string::npos)
			dq.push_back(stoi(str.substr(10)));
		else if (str.find("push_front") != string::npos)
			dq.push_front(stoi(str.substr(11)));
		else if (str.find("pop_back") != string::npos)
		{
			if (!dq.empty())
			{
				cout << dq.back() << endl;
				dq.pop_back();
			}
			else
				cout << -1 << endl;

		}
		else if (str.find("pop_front") != string::npos)
		{
			if (!dq.empty()) {
				cout << dq.front() << endl;
				dq.pop_front();
			}
			else
				cout << -1 << endl;
		}
		else if (str.find("size") != string::npos)
			cout << dq.size() << endl;
		else if (str.find("empty") != string::npos)
			cout << dq.empty() << endl;
		else if (str.find("front") != string::npos)
		{
			if (dq.empty())
				cout << -1 << endl;
			else
				cout << dq.front() << endl;
		}
		else if(str.find("back") != string::npos)
		{
			if (dq.empty())
				cout << -1 << endl;
			else
				cout << dq.back() << endl;
		}

	}

	return 0;
}