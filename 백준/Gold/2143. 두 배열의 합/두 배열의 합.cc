#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void MakeSubSum(vector<int>& A, int N, vector<int>& sub)
{
	for (int i = 0; i < N; i++)
	{
		int sum = A[i];
		sub.push_back(sum);
		for (int j = i + 1; j < N; j++)
		{
			sum += A[j];
			sub.push_back(sum);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T, N, M;
	cin >> T;

	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; i++)
		cin >> A[i];
	
	cin >> M;
	vector<int> B(M);
	for (int i = 0; i < M; i++)
		cin >> B[i];

	vector<int> SubSumA;
	vector<int> SubSumB;

	MakeSubSum(A, N, SubSumA);
	MakeSubSum(B, M, SubSumB);

	sort(begin(SubSumA), end(SubSumA));
	sort(begin(SubSumB), end(SubSumB));

	long long answer = 0;

	int left = 0;
	int right = SubSumB.size()-1;
	while (left < SubSumA.size() && right >= 0)
	{
		int sum = SubSumA[left] + SubSumB[right];
		if (sum < T)
			left++;
		else if (sum > T)
			right--;
		else
		{
			int tmp_left = left;
			int tmp_right = right;
			while (left < SubSumA.size() && SubSumA[left] == SubSumA[tmp_left])
				left++;
			while (right >= 0 && SubSumB[right] == SubSumB[tmp_right])
				right--;

			answer += (long long)(left - tmp_left) * (tmp_right - right);
		}
	}

	cout << answer;
	return 0;
}