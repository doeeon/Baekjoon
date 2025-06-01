#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int M;
	cin >> M;
	cin.ignore();

	vector<bool> S(21, false); //S[0] X

	string str;
	for (int i = 0; i < M; i++)
	{
		getline(cin, str);

		string tmp = str.substr(0, 3);
		if (tmp == "add") //add
			S[stoi(str.substr(4))] = true;
		else if (tmp == "rem") //remove
			S[stoi(str.substr(7))] = false;
		else if (tmp == "che") //check
			cout << S[stoi(str.substr(6))] << '\n';
		else if (tmp == "tog") //toggle
			S[stoi(str.substr(7))] = !S[stoi(str.substr(7))];
		else if (tmp == "all")
			S.assign(21, true);
		else if (tmp == "emp") //empty
			S.assign(21, false);
	}

	return 0;
}