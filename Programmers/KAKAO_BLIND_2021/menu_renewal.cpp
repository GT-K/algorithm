#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

// menu, menu_count
unordered_map<string, int> menu_m;

// menu_length, menu_count, menu_vector
unordered_map<int, pair<int, vector<string>>> menu_size_m;

void dfs(int pos, string ret, string st) {
    if (ret.size() >= 2) {
        menu_m[ret]++;
    }
    for (int i = pos; i < st.size(); i++) {
        ret.push_back(st[i]);
        dfs(i + 1, ret, st);
        ret.pop_back();
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    vector<pair<int, string>> _answer;

    for (auto order : orders) {
        sort(order.begin(), order.end());
        dfs(0, "", order);
    }

    for (auto menu : menu_m) {
        if (menu_size_m[menu.first.size()].first < menu.second){
            menu_size_m[menu.first.size()] = make_pair(menu.second, vector<string>{menu.first});
        } else if (menu_size_m[menu.first.size()].first == menu.second) {
            menu_size_m[menu.first.size()].second.push_back(menu.first);
        }
    }

    for(auto menu_size : course){
        if (menu_size_m[menu_size].first >= 2) {
            for (auto menu : menu_size_m[menu_size].second) {
                answer.emplace_back(menu);
            }
        }
    }

    sort(answer.begin(), answer.end());
    return answer;
}

int main() {
    vector<string> orders = {"ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH"};
    vector<int> course = {2, 3, 4};

    solution(orders, course);
}