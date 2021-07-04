#include <deque>
#include <string>
#include <vector>

using namespace std;
vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size());
    deque<long long> st;

    for (int i = 0; i < prices.size(); i++) {
        while (true) {
            if (st.size() == 0 || st.back() % 10000  <= prices[i] - 1) {
                st.emplace_back((prices[i] - 1) + i * 10000);
                break;
            }
            else {
                answer[st.back() / 10000] = i - st.back() / 10000;
                st.pop_back();
            }
        }
    }
    while (st.size() > 0) {
        answer[st.back() / 10000] = (prices.size() - 1) - st.back() / 10000;
        st.pop_back();
    }
    return answer;
}
// vector<int> solution(vector<int> prices) {
//     vector<int> answer(prices.size());
//     deque<pair<int, int>> st;

//     for (int i = 0; i < prices.size(); i++) {
//         while (true) {
//             if (st.size() == 0 || st.back().first <= prices[i]) {
//                 st.emplace_back(prices[i], i);
//                 break;
//             }
//             else {
//                 answer[st.back().second] = i - st.back().second;
//                 st.pop_back();
//             }
//         }
//     }
//     while (st.size() > 0) {
//         answer[st.back().second] = (prices.size() - 1) - st.back().second;
//         st.pop_back();
//     }
//     return answer;
// }

// #include <stdio.h>

// #include <string>
// #include <vector>
// using namespace std;

// vector<int> solution(vector<int> prices) {
//     vector<int> answer;

//     for (int i = 0; i < prices.size(); i++) {
//         int count = 0;
//         for (int j = i + 1; j < prices.size(); j++) {
//             if (prices[j] < prices[i]) {
//                 count++;
//                 break;
//             } else {
//                 count++;
//             }
//         }
//         answer.push_back(count);
//     }

//     return answer;
// }

int main() {
    vector<int> prices = {1, 2, 3, 2, 3};

    solution(prices);
}