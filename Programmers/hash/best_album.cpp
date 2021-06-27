#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>
#include <iostream>

using namespace std;

struct cmp {
    bool operator()(const pair<int, int> left, const pair<int, int> right) const {
        if (left.first == right.first) {
            return left.second < right.second;
        } else {
            return left.first > right.first;
        }
    }
};

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;

    int N = genres.size();
    unordered_map<string, int> genres_sum;
    map<int, string, greater<int>> genres_order;
    unordered_map<string, set<pair<int, int>, cmp>> genre_plays_order;

    for (int i = 0; i < N; i++) {
        genres_sum[genres[i]] += plays[i];
        genre_plays_order[genres[i]].insert(make_pair(plays[i], i));
    }

    for (auto genre_sum : genres_sum)
        genres_order[genre_sum.second] = genre_sum.first;

    for (auto genre : genres_order) {
        int playCnt = 0;
        for (auto music_num : genre_plays_order[genre.second]) {
            if (playCnt++ >= 2) break;
            answer.emplace_back(music_num.second);
        }
    }

    return answer;
}

int main() {
    vector<vector<string>> genresList = {{"classic", "pop", "classic", "classic", "pop"}};
    vector<vector<int>> playsList = {{500, 600, 150, 800, 2500}};

    for (int i = 0; i < 1; i++)
        for (auto number : solution(genresList[i], playsList[i]))
            cout << number << endl;
}
