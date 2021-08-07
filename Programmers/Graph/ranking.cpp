#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> record_m;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;

    record_m = vector<vector<int>>(n + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= n; i++) record_m[i][i] = 0;
    for (auto result : results) {
        record_m[result[0]][result[1]] = 1;
        record_m[result[1]][result[0]] = -1;
    }

    int flag = 1;
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            if (k == i) continue;
            for (int j = 1; j <= n; j++) {
                if (k == j || i == j || record_m[i][j] != 0) continue;

                if (record_m[i][k] == 1 && record_m[k][j] == 1) {
                    record_m[i][j] = 1;
                    record_m[j][i] = -1;
                    flag = 1;
                }
            }
        }
    }

    for (auto record_p : record_m) {
        int count = 0;
        for (auto record : record_p)
            if (record != 0) count++;
        if (count == n - 1) answer++;
    }

    return answer;
}