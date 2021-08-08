#include <algorithm>
#include <cmath>
#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

unordered_map<string, vector<int>> info_m;
vector<vector<string>> token_lists = {{"cpp", "java", "python"},
                                      {"backend", "frontend"},
                                      {"junior", "senior"},
                                      {"chicken", "pizza"}};

void split(vector<string>& ret, int& score, string st) {
    int prePos = 0;
    for (int i = 0; i < st.length(); i++) {
        if (st[i] == ' ') {
            string tmpSt = st.substr(prePos, i - prePos);
            if (tmpSt != "and")
                ret.emplace_back(tmpSt);
            prePos = i + 1;
        }
    }
    string tmpSt = st.substr(prePos, st.length() - prePos);
    score = stoi(tmpSt);
}

vector<string> make_keys(vector<string> key) {
    vector<string> ret;
    vector<vector<string>> tmpV;
    tmpV.assign(4, {});

    for (int i = 0; i < key.size(); i++) {
        if (key[i] == "-") {
            tmpV[i].insert(tmpV[i].end(), token_lists[i].begin(), token_lists[i].end());
        } else {
            tmpV[i].emplace_back(key[i]);
        }
    }

    for (auto token0 : tmpV[0]) {
        for (auto token1 : tmpV[1]) {
            for (auto token2 : tmpV[2]) {
                for (auto token3 : tmpV[3]) {
                    ret.emplace_back(token0 + token1 + token2 + token3);
                }
            }
        }
    }

    return ret;
}

vector<int> solution(vector<string> infos, vector<string> querys) {
    vector<int> answer;
    
    for (auto info : infos) {
        vector<string> info_split;

        string key = "";
        int score;
        split(info_split, score, info);

        for (auto token : info_split) key.append(token);

        info_m[key].emplace_back(score);
    }

    for (auto scores : info_m) {
        sort(scores.second.begin(), scores.second.end());
    }

    for (auto query : querys) {
        vector<string> query_split;

        vector<string> keys;
        int score;
        split(query_split, score, query);

        keys = make_keys(query_split);

        int count = 0;
        for(auto key : keys){
            for (auto info_score : info_m[key]){
                if (info_score >= score) count++;
            }
        }

        answer.emplace_back(count);
    }

    return answer;
}

int main() {
    vector<string> infos = {"java backend junior pizza 150", "python frontend senior chicken 210", "python frontend senior chicken 150", "cpp backend senior pizza 260", "java backend junior chicken 80", "python backend senior chicken 50"};
    vector<string> querys = {"java and backend and junior and pizza 100", "python and frontend and senior and chicken 200", "cpp and - and senior and pizza 250", "- and backend and senior and - 150", "- and - and - and chicken 100", "- and - and - and - 150"};

    solution(infos, querys);
}