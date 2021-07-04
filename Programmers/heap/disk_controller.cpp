#include <algorithm>
#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int solution(vector<vector<int>> jobs) {
    deque<vector<int>> q(jobs.begin(), jobs.end());
    sort(q.begin(), q.end());

    int curTime = q.front()[0] + q.front()[1];
    int answer = q.front()[1];
    q.pop_front();

    while (q.size() > 0) {
        auto tmpPos = q.begin();
        for (auto iter = q.begin(); iter != q.end(); iter++) {
            if ((*iter)[0] > curTime)
                break;
            else if ((*iter)[1] < (*tmpPos)[1])
                tmpPos = iter;
        }
        answer += (curTime < (*tmpPos)[0] ? 0 : (curTime - (*tmpPos)[0])) + (*tmpPos)[1];
        curTime = (curTime < (*tmpPos)[0] ? (*tmpPos)[0] : curTime) + (*tmpPos)[1];
        q.erase(tmpPos);
    }

    return answer / jobs.size();
}

int main() {
    vector<vector<vector<int>>> jobs_list = {{{0, 3}, {1, 9}, {2, 6}}, {{0, 3}, {1, 3}, {8, 6}}};

    for (auto jobs : jobs_list)
        cout << solution(jobs) << endl;
}
// #include <algorithm>
// #include <iostream>
// #include <queue>
// #include <vector>
// using namespace std;

// bool comp(vector<int> a, vector<int> b) {
//     if (a[0] == b[0])
//         return a[1] < b[1];
//     else
//         return a[0] < b[0];
// }
// int solution(vector<vector<int>> jobs) {
//     /*int main(){
// 	vector<vector<int>> jobs = { {0,3},{1,9},{2,6} };
// */
//     priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
//     int answer = 0;
//     int cur_jobs = 0;
//     int cur_time = 0;

//     sort(jobs.begin(), jobs.end(), comp);
//     while (1) {
//         while (cur_jobs < jobs.size() && jobs[cur_jobs][0] <= cur_time) {
//             pq.push(make_pair(jobs[cur_jobs][1], jobs[cur_jobs][0]));
//             cur_jobs++;
//         }
//         if (cur_jobs < jobs.size() && pq.size() == 0) {
//             pq.push(make_pair(jobs[cur_jobs][1], jobs[cur_jobs][0]));
//             cur_jobs++;
//         }
//         if (pq.top()[1] > cur_time) {
//             answer += pq.top()[0];
//             cur_time = pq.top()[1] + pq.top()[0];
//         } else {
//             answer += pq.top()[0] + (cur_time - pq.top()[1]);
//             cur_time += pq.top()[0];
//         }
//         pq.pop();
//         if (cur_jobs == jobs.size() && pq.empty()) break;
//     }
//     cout << answer / jobs.size();
//     return answer / jobs.size();
// }