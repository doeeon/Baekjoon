#include <string>
#include <vector>

using namespace std;

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;
    
    for(int i=0; i<schedules.size(); i++) {
        int cnt = 0;
        for(int j=0; j<7; j++)
        {
            if((startday+j-1)%7 + 1 == 6 || (startday+j-1)%7 + 1 == 7)
                cnt++;
            else
            {
                int limit = schedules[i] + 10;
                if(limit%100 >= 60)
                {
                    limit = ((limit/100)+1)*100 + (limit%100)%60;
                }
                if(timelogs[i][j] <= limit)
                    cnt++;
            }
        }
        
        if(cnt == 7)
            answer++;
    }
    
    return answer;
}