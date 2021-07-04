#include <cmath>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;

    int N = progresses.size();
    vector<int> q;

    int count = 1;
    int pre = ceil((100.0 - progresses[0]) / speeds[0]);

    for (int i = 1; i < N; i++) {
        int cur = ceil((100.0 - progresses[i]) / speeds[i]);
        if (cur > pre) {
            answer.emplace_back(count);
            count = 1;
            pre = cur;
        } else {
            count++;
        }
    }
    answer.emplace_back(count);

    return answer;
}
int main() {
    vector<vector<int>> progresses_list = {{93, 30, 55}, {95, 90, 99, 99, 80, 80}};
    vector<vector<int>> speeds_list = {{1, 30, 5}, {1, 1, 1, 1, 1, 1}};

    for (int i = 0; i < progresses_list.size(); i++) {
        for (auto iter : solution(progresses_list[i], speeds_list[i]))
            cout << iter << "\t";
        cout << endl;
    }
}

// 문제가 개편되었습니다. 이로 인해 함수 구성이나 테스트케이스가 변경되어, 과거의 코드는 동작하지 않을 수 있습니다.
// 새로운 함수 구성을 적용하려면 [코드 초기화] 버튼을 누르세요. 단, [코드 초기화] 버튼을 누르면 작성 중인 코드는 사라집니다.
// #include <stdio.h>

// #include <queue>
// #include <string>
// #include <vector>

// using namespace std;

// queue<pair<int, int>> q;

// vector<int> solution(vector<int> progresses, vector<int> speeds) {
//     vector<int> answer;
//     for (int i = 0; i < progresses.size(); i++) {
//         q.push(make_pair(progresses[i], speeds[i]));
//     }

//     while (q.size() != 0) {
//         int day = 0;
//         int count = 0;
//         while ((100 - q.front().first) - q.front().second * day > 0) {
//             day++;
//         }

//         while ((100 - q.front().first) - q.front().second * day <= 0) {
//             count++;
//             q.pop();
//         }
//         answer.push_back(count);
//     }
//     return answer;
// }