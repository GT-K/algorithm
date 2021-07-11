#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> ret;
    vector<int> count(3, 0);

    vector<vector<int>> student_answer_list = {
        {1, 2, 3, 4, 5},
        {2, 1, 2, 3, 2, 4, 2, 5},
        {3, 3, 1, 1, 2, 2, 4, 4, 5, 5}};

    for (int i = 0; i < answers.size(); i++) {
        if (student_answer_list[0][i % student_answer_list[0].size()] == answers[i])
            count[0]++;
        if (student_answer_list[1][i % student_answer_list[1].size()] == answers[i])
            count[1]++;
        if (student_answer_list[2][i % student_answer_list[2].size()] == answers[i])
            count[2]++;
    }

    map<int, vector<int>, greater<int>> m;
    for (int i = 0; i < count.size(); i++)
        m[count[i]].emplace_back(i + 1);

    return (*m.begin()).second;
}

int main() {
    vector<vector<int>> answers_list = {{1, 2, 3, 4, 5},
                                        {1, 3, 2, 4, 2}};

    for (auto item : answers_list)
        solution(item);
}

// #include <algorithm>
// #include <string>
// #include <vector>

// using namespace std;

// vector<int> answer1 = {1, 2, 3, 4, 5};
// vector<int> answer2 = {2, 1, 2, 3, 2, 4, 2, 5};
// vector<int> answer3 = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
// vector<vector<int>> count_arr;

// bool comp(vector<int> a, vector<int> b) {
//     if (a[0] == b[0])
//         return a[1] < b[1];
//     else
//         return a[0] > b[0];
// }

// vector<int> solution(vector<int> answers) {
//     vector<int> answer;
//     count_arr.assign(3, vector<int>(2, 0));

//     count_arr[0][1] = 1;
//     count_arr[1][1] = 2;
//     count_arr[2][1] = 3;

//     for (int i = 0; i < answers.size(); i++) {
//         if (answers[i] == answer1[i % answer1.size()]) count_arr[0][0]++;
//         if (answers[i] == answer2[i % answer2.size()]) count_arr[1][0]++;
//         if (answers[i] == answer3[i % answer3.size()]) count_arr[2][0]++;
//     }

//     sort(count_arr.begin(), count_arr.end(), comp);

//     if (count_arr[0][0] == 0)
//         return answer;
//     else
//         answer.push_back(count_arr[0][1]);

//     for (int i = 1; i < count_arr.size(); i++) {
//         if (count_arr[0][0] == count_arr[i][0])
//             answer.push_back(count_arr[i][1]);
//         else
//             return answer;
//     }
//     return answer;
// }