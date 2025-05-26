#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    
    vector<vector<int>> cnt(friends.size(), vector<int>(friends.size(), 0));
    for(int i=0; i<friends.size(); i++)
        cnt[i][i] = -1;
        
    map<string, int> idx;
    map<string, int> score;
    for(int i=0; i<friends.size(); i++) {
        idx[friends[i]] = i;
        score[friends[i]] = 0;
    }
    
    for(int i=0; i<gifts.size(); i++)
    {
        string give = gifts[i].substr(0, gifts[i].find(' '));
        string receive = gifts[i].substr(gifts[i].find(' ')+1);
        
        cnt[idx[give]][idx[receive]]++;
        score[give]++;
        score[receive]--;
    }
    
    vector<int> predict(friends.size(), 0);
    for(int i=0; i<friends.size()-1; i++)
        for(int j=i+1; j<friends.size(); j++)
        {
            if(cnt[idx[friends[i]]][idx[friends[j]]] > cnt[idx[friends[j]]][idx[friends[i]]])
                predict[i]++;
            else if(cnt[idx[friends[i]]][idx[friends[j]]] < cnt[idx[friends[j]]][idx[friends[i]]])
                predict[j]++;
            else {
                if(score[friends[i]] > score[friends[j]])
                    predict[i]++;
                else if(score[friends[i]] < score[friends[j]])
                    predict[j]++;
            }
        }
    
    answer = *max_element(predict.begin(), predict.end());
    return answer;
}