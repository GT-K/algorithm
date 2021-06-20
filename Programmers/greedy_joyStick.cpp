#include <iostream>
#include <string>

using namespace std;


int solution(string name)
{
    int answer = 0;

    int curIndex = 0;
    while (true)
    {
        answer += min((name[curIndex] - 'A' + 26) % 26, ('A' - name[curIndex] + 26) % 26);
        name[curIndex] = 'A';

        int i;
        for (i = 1; i < name.size(); i++)
        {
            if (name[(curIndex + i + name.size()) % name.size()] != 'A')
            {
                answer += i;
                curIndex = (curIndex + i + name.size()) % name.size();
                break;
            }
            else if (name[(curIndex - i + name.size()) % name.size()] != 'A')
            {
                answer += i;
                curIndex = (curIndex - i + name.size()) % name.size();
                break;
            }
        }

        if(i == name.size())
            break;
    }

    return answer;
}

int main()
{
    string st[] = {"JEROEN", "JAN", "JAZ"};

    for (auto item : st)
        cout << solution(item) << endl;
}