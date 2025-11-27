#include <iostream>
#include <vector>

using namespace std;

void Pre(int s, int e, vector<int>& arr)
{
	if (s < e)
	{
		bool IsRight = false;
		for (int i = s + 1; i < e; i++)
			if (arr[s] < arr[i])
			{
				IsRight = true;
				Pre(s + 1, i, arr); // left sub-tree
				Pre(i, e, arr); // right sub-tree
				break;
			}

		if (!IsRight) // only exist left sub-tree
			Pre(s + 1, e, arr); // s+1 == e 인경우 if문에 의해 걸러지므로 상관 x

		cout << arr[s] << endl;; // root node
	}
}

int main()
{
	vector<int> arr;
	int x;
	while (cin >> x)
		arr.push_back(x);
	
	Pre(0, arr.size(), arr);

	return 0;
}