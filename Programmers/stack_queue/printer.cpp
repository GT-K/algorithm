#include <map>
#include <deque>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;

    map<int, int, greater<int>> m;
    deque<pair<int, int>> q;

    int index = 0;
    for(auto item : priorities)
    {
        q.emplace_back(item, index++);
        m[item]++;
    }

    for(auto item : m)
    {
        int count = 0;
        while (count < item.second) {
            if (q.front().first != item.first) {
                q.emplace_back(q.front());
                q.pop_front();
            } else {
                answer++;
                count++;
                if (q.front().second == location) return answer;
                q.pop_front();
            }
        }
    }

    return answer;
}

int main() {
    vector<vector<int>> priorities_list = {{2, 1, 3, 2}, {1, 1, 9, 1, 1, 1}};
    vector<int> location_list = {3, 0};

    for (int i = 0; i < 2; i++)
        cout << solution(priorities_list[i], location_list[i]) << endl;
}
// #include <queue>
// #include <string>
// #include <vector>

// using namespace std;

// queue<pair<int, int>> q;

// int answer = 1;
// int tmp;
// int solution(vector<int> priorities, int location) {
//     for (int i = 0; i < priorities.size(); i++) {
//         q.push(make_pair(priorities[i], i));
//     }

//     while (1) {
//         int max = 0;
//         for (int i = 0; i < q.size(); i++) {
//             if (q.front().first > max) max = q.front().first;
//             q.push(make_pair(q.front().first, q.front().second));
//             q.pop();
//         }

//         for (int i = 0; q.front().first != max; i++) {
//             q.push(make_pair(q.front().first, q.front().second));
//             q.pop();
//         }
//         if (q.front().second == location)
//             return answer;
//         else {
//             q.pop();
//             answer++;
//         }
//     }
// }