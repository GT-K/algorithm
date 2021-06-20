#include <iostream>
#include <string>
#include <vector>
#include <deque>

using namespace std;

string solution(string number, int k)
{
    string answer = "";
    int final_size = number.size() - k;

    int count = 0;
    int curIndex = 1;
    deque<int> q;

    q.emplace_back(number[0] - '0');

    while (count < k && curIndex < number.size())
    {
        if (!q.empty() && q.back() < number[curIndex] - '0')
        {
            q.pop_back();
            count++;
        }
        else
        {
            q.emplace_back(number[curIndex] - '0');
            curIndex++;
        }
    }

    while(curIndex < number.size())
    {
        q.emplace_back(number[curIndex++] - '0');
    }

    while(count++ < k)
    {
        q.pop_back();
    }

    for(auto item : q)
        answer.push_back(item + '0');

    return answer;
}

int main()
{
    vector<string> number = {"1924", "1231234", "4177252841"};
    vector<int> k = {2, 3, 4};

    for (int i = 0; i < 3; i++)
        cout << solution(number[i], k[i]) << endl;
}