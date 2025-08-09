#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(string word) {
    int answer = 0;
    
    string alpha[5] = {"A", "E", "I", "O", "U"};
    vector<string> dict;
    dict.push_back("A");
    dict.push_back("E");
    dict.push_back("I");
    dict.push_back("O");
    dict.push_back("U");
    
    int n = 0;
    for(int i=0; i<4; i++)
    {
        int size = dict.size();
        for(; n<size; n++)
            for(int k=0; k<5; k++)
                dict.push_back(dict[n]+alpha[k]);

        n = size;
    }
    
    sort(dict.begin(), dict.end());
    answer = find(dict.begin(), dict.end(), word) - dict.begin() + 1;
    
    return answer;
}