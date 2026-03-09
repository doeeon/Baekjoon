#include <vector>
#include <iostream>

using namespace std;

int main()
{
    int T;
    cin >> T;
    
    for(int t=0; t<T; t++)
    {
        int N, M;
        cin >> N >> M;
        
        //mCn = m-1Cn + m-1Cn-1
        vector<vector<int>> dp(M+1, vector<int>(M+1, 0));
        
        for(int i=1; i<=M; i++)
        {
            dp[i][1] = i;
            dp[i][i] = 1;
        }
        
        for(int i=3; i<=M; i++)
            for(int j=2; j<i; j++)
                dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
        
        cout << dp[M][N] << '\n';
    }

    return 0;
}