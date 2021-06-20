#include <algorithm>
#include <iostream>
#include <list>
#include <vector>

using namespace std;

bool comp(vector<int> a, vector<int> b)
{
    return a[2] < b[2];
}

int solution(int n, vector<vector<int>> costs)
{
    sort(costs.begin(), costs.end(), comp);

    int answer = 0;
    vector<int> v = vector<int>(n);
    vector<list<int>> linkLists = vector<list<int>>(n);
    int linkListsCount = 0;

    for (auto cost : costs)
    {
        if ((v[cost[0]] && !v[cost[1]]) || (!v[cost[0]] && v[cost[1]]))
        {
            auto toVisit = (!v[cost[0]]) ? cost[0] : cost[1];
            auto visited = (v[cost[0]]) ? cost[0] : cost[1];

            int linkListsIndex;
            for (linkListsIndex = 0; linkListsIndex < linkListsCount; linkListsIndex++)
            {
                if (find(linkLists[linkListsIndex].begin(), linkLists[linkListsIndex].end(), visited) != linkLists[linkListsIndex].end())
                    break;
            }
            linkLists[linkListsIndex].emplace_back(toVisit);
            v[toVisit] = 1;
            answer += cost[2];
        }
        else if (!v[cost[0]] && !v[cost[1]])
        {
            linkLists[linkListsCount].emplace_back(cost[0]);
            linkLists[linkListsCount++].emplace_back(cost[1]);
            v[cost[0]] = 1;
            v[cost[1]] = 1;
            answer += cost[2];
        }
        else if (v[cost[0]] && v[cost[1]])
        {
            int v0Index = -1, v1Index = -1;
            for (int i = 0; i < linkListsCount; i++)
            {
                if (find(linkLists[i].begin(), linkLists[i].end(), cost[0]) != linkLists[i].end())
                    v0Index = i;
                if (find(linkLists[i].begin(), linkLists[i].end(), cost[1]) != linkLists[i].end())
                    v1Index = i;
                if (v0Index != -1 && v1Index != -1)
                    break;
            }

            if (v0Index != v1Index)
            {
                linkLists[min(v0Index, v1Index)].merge(linkLists[max(v0Index, v1Index)]);
                answer += cost[2];
            }
        }

        if (linkLists[0].size() == n)
            break;
    }

    return answer;
}

int main()
{
    vector<int> n = {5, 5, 4, 5, 6, 5, 5, 5};
    vector<vector<vector<int>>> costs = {
        {{0, 1, 5}, {1, 2, 3}, {2, 3, 3}, {3, 1, 2}, {3, 0, 4}, {2, 4, 6}, {4, 0, 7}},
        {{0, 1, 1}, {3, 4, 1}, {1, 2, 2}, {2, 3, 4}},
        {{0, 1, 5}, {1, 2, 3}, {2, 3, 3}, {1, 3, 2}, {0, 3, 4}},
        {{0, 1, 1}, {3, 1, 1}, {0, 2, 2}, {0, 3, 2}, {0, 4, 100}},
        {{0, 1, 5}, {0, 3, 2}, {0, 4, 3}, {1, 4, 1}, {3, 4, 10}, {1, 2, 2}, {2, 5, 3}, {4, 5, 4}},
        {{0, 1, 1}, {2, 3, 1}, {3, 4, 2}, {1, 2, 2}, {0, 4, 100}},
        {{0, 1, 1}, {0, 4, 5}, {2, 4, 1}, {2, 3, 1}, {3, 4, 1}},
        {{0, 1, 1}, {0, 2, 2}, {0, 3, 3}, {0, 4, 4}, {1, 3, 1}}};

    for (int i = 0; i < 8; i++)
        cout << solution(n[i], costs[i]) << endl;
}