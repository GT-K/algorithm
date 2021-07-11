#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;

    sort(rocks.begin(), rocks.end(), [](int left, int right) { return left < right; });

    int left = 0, right = distance, mid;

    while(left <= right)
    {
        vector<int> visited(rocks.size());
        mid = (left + right) / 2;

        for (int i = 1; i < rocks.size(); i++) {
            if()
        }
    }

    return answer;
}