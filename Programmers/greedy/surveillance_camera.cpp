#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(vector<int> a, vector<int> b)
{
    if(a[0] != b[0])
        return a[0] < b[0];
    else
        return a[1] < b[1];
}

int solution(vector<vector<int>> routes)
{
    sort(routes.begin(), routes.end(), comp);

    int answer = 1;
    int preLeft = routes[0][0];
    int preRight = routes[0][1];
    for (int i = 1; i < routes.size(); i++)
    {
        int curLeft = routes[i][0];
        int curRight = routes[i][1];

        if(curLeft > preRight)
        {
            answer++;
            preLeft = curLeft;
            preRight = curRight;
        }
        else
        {
            preLeft = max(preLeft, curLeft);
            preRight = min(preRight, curRight);
        }
    }

    return answer;
}

int main()
{
    vector<vector<int>> routes = {{-20, 15}, {-14, -5}, {-18, -13}, {-5, -3}};

    cout << solution(routes) << endl;
}