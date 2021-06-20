#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool comp(int a, int b)
{
    return a < b;
}

int solution(vector<int> people, int limit)
{
    int answer = 0;
    vector<int> v = vector<int>(people.size());

    sort(people.begin(), people.end(), comp);

    int right = people.size() - 1;
    int left = 0;

    while(left <= right)
    {
        if(people[left] + people[right] > limit)
        {
            answer++;
            right--;
        }
        else
        {
            answer++;
            right--;
            left++;
        }
    }

    return answer;
}

int main()
{
    vector<vector<int>> people = {{70, 50, 80, 50}, {70, 80, 50}};
    vector<int> limit = {100, 100};

    for (int i = 0; i < 2; i++)
        cout << solution(people[i], limit[i]) << endl;
}
