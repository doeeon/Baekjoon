#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(string word) {
    int answer = 0;
    string ref = "AEIOU";
    for(int i=0; i<word.size(); i++)
    {
        int tmp = ref.find(word[i]);
        answer += tmp;
        for(int j=0; j<5-i-1; j++)
        {
            tmp *= 5;
            answer += tmp;
        }
        answer ++;
    }
    return answer;
}