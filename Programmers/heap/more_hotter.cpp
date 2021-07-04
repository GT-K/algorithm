#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> s;

    for(auto item : scoville)
    {
        s.push(item);
    }
    while (s.top() < K) {
        if (s.size() == 1 && s.top() < K) return -1;
        int item1 = s.top();
        s.pop();
        int item2 = s.top();
        s.pop();

        s.push(item1 + item2 * 2);
        answer++;
    }
    return answer;
}

int main()
{
    vector<int> scovile = {1, 2, 3, 9, 10, 12};
    int K = 7;
    solution(scovile, K);
}

// #include <iostream>
// #include <queue>
// #include <string>
// #include <vector>
// using namespace std;

// int solution(vector<int> scoville, int K) {
//     int answer = 0;

//     priority_queue<int, vector<int>, greater<int>> pq;

//     for (auto i : scoville) pq.push(i);

//     while (pq.top() < K && pq.size() > 1) {
//         int tmp1, tmp2;
//         tmp1 = pq.top();
//         pq.pop();
//         tmp2 = pq.top();
//         pq.pop();
//         pq.push(tmp1 + tmp2 * 2);
//         answer++;
//     }
//     if (pq.top() > K)
//         return answer;
//     else
//         return -1;
// }