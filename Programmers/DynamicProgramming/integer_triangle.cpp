#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;

    for (int r = 1; r < triangle.size(); r++) {
        for (int c = 0; c < triangle[r].size(); c++) {
            if (c == 0)
                triangle[r][c] += triangle[r - 1][c];
            else if (c == triangle[r].size() - 1)
                triangle[r][c] += triangle[r - 1][c - 1];
            else
                triangle[r][c] += max(triangle[r - 1][c], triangle[r - 1][c - 1]);
        }
    }

    return *max_element(triangle[triangle.size() - 1].begin(), triangle[triangle.size() - 1].end());
}

int main() {
    vector<vector<int>> triangle = {{7}, {3, 8}, {8, 1, 0}, {2, 7, 4, 4}, {4, 5, 2, 6, 5}};
    cout << solution(triangle);
}