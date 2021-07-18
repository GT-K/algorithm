//#include <string>
#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

int solution(int N, int number) {
    int answer = 0;
    unordered_map<int, set<int>> m;

    int count = 1;
    while (count <= 9) {
        int num = N;
        for (int i = 1; i < count; i++) num = num * 10 + N;

        if (num == number || -num == number) return count;
        m[count].insert(num);

        for (int i = 1; i <= count / 2; i++) {
            for (auto item1 : m[count - i]) {
                for (auto item2 : m[i]) {
                    vector<int> tmp_v;
                    tmp_v.emplace_back(item1 + item2);
                    tmp_v.emplace_back(item1 - item2);
                    tmp_v.emplace_back(item1 * item2);
                    tmp_v.emplace_back(item1 >= item2 && item2 != 0 ? item1 / item2 : 0);

                    for (auto num : tmp_v) {
                        if (num == number || -num == number) return count;
                        m[count].insert(num);
                    }
                }
            }
        }
        count++;
    }

    return -1;
}

int main() {
    int N = 8, number = 5800;

    cout << solution(N, number);
}