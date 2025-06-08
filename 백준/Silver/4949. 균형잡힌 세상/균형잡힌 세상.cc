#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
	string str;
	while (1)
	{
		getline(cin, str);
		if (str == ".")
			break;

		stack<char> st;
		bool balanced = true;
		for (int i = 0; i < str.size() && balanced; i++)
		{
			if (str[i] == '(')
				st.push('(');
			else if (str[i] == '[')
				st.push('[');
			else if (str[i] == ')')
			{
				if (st.empty())
					balanced = false;
				else
				{
					if (st.top() == '(')
						st.pop();
					else
						balanced = false;
				}
			}
			else if (str[i] == ']')
			{
				if (st.empty())
					balanced = false;
				else
				{
					if (st.top() == '[')
						st.pop();
					else
						balanced = false;
				}
			}
		}

		if (!st.empty())
			balanced = false;

		if (balanced)
			cout << "yes\n";
		else
			cout << "no\n";
	}

	return 0;
}