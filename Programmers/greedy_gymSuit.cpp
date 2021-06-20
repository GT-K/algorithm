#include <vector>
#include <iostream>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve)
{
    int ret = 0;
    vector<int> gymSuitList = vector<int>(n + 1, 1);

    for (auto item : lost)
        gymSuitList[item]--;
    for (auto item : reserve)
        gymSuitList[item]++;

    for (int i = 1; i <= n; i++)
    {
        if(gymSuitList[i] == 0)
        {
            if(i - 1 >= 1 && gymSuitList[i-1] > 1)
            {
                gymSuitList[i]++;
                gymSuitList[i - 1]--;
            }
            else if (i + 1 <= n && gymSuitList[i + 1] > 1)
            {
                gymSuitList[i]++;
                gymSuitList[i + 1]--;
            }
        }
    }
    for (int i = 1; i <= n; i++)
        if(gymSuitList[i] > 0)
            ret++;

    return ret;
}

int main()
{
    vector<int> n = {5, 5, 3};
    vector<vector<int>> lost = {{2, 4}, {2, 4}, {3}};
    vector<vector<int>> reserve = {{1, 3, 5}, {3}, {1}};

    for (int i = 0; i < 3;i++)
        cout << solution(n[i], lost[i], reserve[i]) << endl;

}

// #include <string>
// #include <vector>
// using namespace std;

// int solution(int n, vector<int> lost, vector<int> reserve)
// {
//     int answer = 0;
//     vector<int> v(n + 2, 1);

//     for (auto i : lost)
//         v[i]--;
//     for (auto i : reserve)
//         v[i]++;

//     for (int i = 0; i < v.size(); i++)
//     {
//         if (v[i] == 2 && v[i - 1] == 0)
//         {
//             v[i]--;
//             v[i - 1]++;
//         }
//         else if (v[i] == 2 && v[i + 1] == 0)
//         {
//             v[i]--;
//             v[i + 1]++;
//         }
//     }
//     for (auto i : v)
//         if (i != 0)
//             answer++;
//     return answer - 2;
// }