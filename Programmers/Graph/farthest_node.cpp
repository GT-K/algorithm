#include <algorithm>
#include <deque>
#include <unordered_map>
#include <vector>
#include <iostream>

using namespace std;

unordered_map<int, vector<int>> m;
unordered_map<int, int> v;

deque<pair<int, int>> q;

int solution(int n, vector<vector<int>> edges) {
    int max_count = 0;
    int max_dist = 0;
    for (auto edge : edges) {
        m[edge[0]].emplace_back(edge[1]);
        m[edge[1]].emplace_back(edge[0]);
    }

    q.emplace_back(make_pair(1, 0));
    v[1] = 1;

    while (!q.empty()) {
        for (auto node : m[q.front().first]) {
            if (!v[node]) {
                q.emplace_back(make_pair(node, q.front().second + 1));
                v[node] = 1;
            }
        }
        if(q.front().second > max_dist){
            max_dist = q.front().second;
            max_count = 1;
        } else {
            max_count += 1;
        }

        q.pop_front();
    }

    return max_count;
}

int main()
{
    int n = 6;
    vector<vector<int>> edges = {{3, 6}, {4, 3}, {3, 2}, {1, 3}, {1, 2}, {2, 4}, {5, 2}};

    cout << solution(n, edges) << endl;
}