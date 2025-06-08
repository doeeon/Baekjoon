#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
	int K;
	cin >> K;
	cin.ignore();

	string str;
	stack<int> st;
	for (int i = 0; i < K; i++)
	{
		getline(cin, str);
		if (str.substr(0, 2) == "pu") // push
			st.push(stoi(str.substr(4)));
		else if (str.substr(0, 2) == "po") // pop
		{
			if (st.empty())
				cout << -1 << '\n';
			else
			{
				cout << st.top() << '\n';
				st.pop();
			}
		}
		else if (str.substr(0, 2) == "si") // size
			cout << st.size() << '\n';
		else if (str.substr(0, 2) == "em") // empty
			cout << st.empty() << '\n';
		else //top
		{
			if (st.empty())
				cout << -1 << '\n';
			else
				cout << st.top() << '\n';
		}
	}

	return 0;
}