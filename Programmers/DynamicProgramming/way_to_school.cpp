#include <cstring>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int map[100][100];

void printMap(int m, int n) {
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++)
            cout << map[r][c] << " ";
        cout << endl;
    }
    cout << endl;
}

int solution(int max_c, int max_r, vector<vector<int>> puddles) {
    int answer = 0;

    map[0][0] = 1;
    for (auto puddle : puddles)
        map[puddle[1] - 1][puddle[0] - 1] = -1;

    for (int d = 1; d <= (max_c - 1) + (max_r - 1); d++) {
        int r = d > max_r - 1 ? max_r - 1 : d;
        int c = d - r;
        for (; (r >= 0 && r < max_r) && (c >= 0 && c < max_c); r--, c++) {
            if (map[r][c] == -1) {
                map[r][c] = 0;
                continue;
            }
            map[r][c] = (c - 1 >= 0) ? map[r][c - 1] : 0;
            map[r][c] += (r - 1 >= 0) ? map[r - 1][c] : 0;
            map[r][c] %= 1000000007;
        }
    }
    return map[max_r - 1][max_c - 1];
}

int main() {
    cout << solution(4, 3, {{2, 2}}) << endl;
    printMap(5, 5);
}