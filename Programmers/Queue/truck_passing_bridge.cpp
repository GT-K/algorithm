// #include <string>
// #include <vector>
// #include <iostream>
// #include <deque>

// using namespace std;

// int solution(int bridge_length, int bridge_weight, vector<int> truck_weights) {
//     int answer = 0;
//     deque<pair<int, int>> bridge;

//     int trucks_weight = 0;
//     int truck_index = 0;

//     trucks_weight += truck_weights[truck_index];
//     bridge.emplace_back(truck_weights[truck_index++], answer);

//     while (bridge.size() > 0) {
//         if (bridge.front().second + bridge_length == answer) {
//             trucks_weight -= bridge.front().first;
//             bridge.pop_front();
//         }
//         if (trucks_weight + truck_weights[truck_index] < bridge_weight && bridge.size() < bridge_length) {
//             if()
//             bridge.emplace_back(truck_weights[truck_index++], answer);
//             trucks_weight += bridge.back().first;
//         }
//         answer++;
//     }

//     return answer;
// }

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;

    queue<int> q;
    int truck_count = 0;
    int cur_weight = 0;

    for (int i = 0; i < bridge_length; i++) q.push(0);

    while (1) {
        if (truck_count < truck_weights.size() && cur_weight + truck_weights[truck_count] <= weight) {
            cur_weight -= q.front();
            q.pop();
            q.push(truck_weights[truck_count]);
            cur_weight += truck_weights[truck_count++];
            answer++;
        } else {
            cur_weight -= q.front();
            q.pop();
            if (truck_count < truck_weights.size() && cur_weight + truck_weights[truck_count] <= weight) {
                q.push(truck_weights[truck_count]);
                cur_weight += truck_weights[truck_count++];
            } else {
                q.push(0);
            }
            answer++;
        }
        if (cur_weight == 0 && truck_count == truck_weights.size()) break;
    }
    return answer;
}

int main() {
    vector<int> bridge_length_list = {2, 100, 100};
    vector<int> weight_list = {10, 100, 100};
    vector<vector<int>> truck_weights_list = {{7, 4, 5, 6}, {10}, {10, 10, 10, 10, 10, 10, 10, 10, 10, 10}};

    for (int i = 0; i < 3; i++)
        cout << solution(bridge_length_list[i], weight_list[i], truck_weights_list[i]) << endl;
}
