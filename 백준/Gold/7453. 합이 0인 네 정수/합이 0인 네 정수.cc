#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	vector<vector<int>> arr(4, vector<int>(N));
	for (int i = 0; i < N; i++)
		cin >> arr[0][i] >> arr[1][i] >> arr[2][i] >> arr[3][i];

	vector<int> A;
	vector<int> B;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			A.push_back(arr[0][i] + arr[1][j]);
			B.push_back(arr[2][i] + arr[3][j]);
		}

	sort(A.begin(), A.end());
	sort(begin(B), end(B));

	int a_idx = 0;
	int b_idx = B.size() - 1;

	int sum = 0;
	long long answer = 0;
	while (a_idx < A.size() && b_idx >= 0)
	{
		sum = A[a_idx] + B[b_idx];
		if (sum > 0)
			b_idx--;
		else if (sum < 0)
			a_idx++;
		else //sum == 0
		{
			int tmpA = a_idx;
			int tmpB = b_idx;

			while (a_idx < A.size() && A[tmpA] == A[a_idx])
				a_idx++;
			while (b_idx >=0 && B[tmpB] == B[b_idx])
				b_idx--;

			answer += (long long)(a_idx - tmpA) * (tmpB - b_idx);
		}
	}

	cout << answer;
	
	return 0;
}