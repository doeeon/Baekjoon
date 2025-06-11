#include <iostream>
#include <string>

using namespace std;
// 식에 '-'가 있으면, 그 뒤의 모든 수는 음수로 처리 가능
int main() {
	string str;
	cin >> str;

	int answer = 0;
	bool minus = false;
	string num = "";
	for (int i = 0; i < str.size(); i++)
	{
		if (isdigit(str[i]))
			num += str[i];
		else if (!minus)
		{
			answer += stoi(num);
			num = "";
			if(str[i] == '-')
				minus = true;
		}
		else // if(!isdigit(str[i] && minus == true)
		{
			answer -= stoi(num);
			num = "";
		}
	}

	if (!minus)
		answer += stoi(num);
	else
		answer -= stoi(num);

	cout << answer;
	return 0;
}