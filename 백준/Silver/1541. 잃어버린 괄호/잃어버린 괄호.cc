#include <iostream>
#include <string>

using namespace std;
// 식에 '-'가 있으면, 그 뒤의 모든 수는 음수로 처리 가능
int main() {
	string str;
	cin >> str;

	int pos = 0;
	int neg = 0;
	bool minus = false;
	string num = "";
	for (int i = 0; i < str.size(); i++)
	{
		if (isdigit(str[i]))
			num += str[i];
		else if (!minus)
		{
			pos += stoi(num);
			num = "";
			if(str[i] == '-')
				minus = true;
		}
		else // if(!isdigit(str[i] && minus == true)
		{
			neg += stoi(num);
			num = "";
		}
	}

	if (!minus)
		pos += stoi(num);
	else
		neg += stoi(num);

	int answer = pos - neg;
	cout << answer;
	return 0;
}