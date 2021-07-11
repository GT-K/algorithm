#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int sum = brown + yellow;

    for (int row = 1; row <= sqrt(yellow); row++) {
        int col = (yellow % row == 0) ? yellow / row : -1;

        if (col < 0 || (row + 2) * (col + 2) != sum) continue;
        return {col + 2, row + 2};
    }
}