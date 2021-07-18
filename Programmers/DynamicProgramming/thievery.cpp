#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> money) {
    int ret = 0;

    vector<int> dp_first(money.size()), dp_last(money.size());

    dp_first[0] = money[0];
    dp_last[0] = 0;

    dp_first[1] = max(money[0], money[1]);
    dp_last[1] = money[1];

    for (int i = 2; i < money.size() - 1; i++) {
        dp_first[i] = max(dp_first[i - 1], money[i] + dp_first[i - 2]);
        dp_last[i] = max(dp_last[i - 1], money[i] + dp_last[i - 2]);
    }

    dp_first[money.size() - 1] = dp_first[money.size() - 2];
    dp_last[money.size() - 1] = max(dp_last[money.size() - 2], money[money.size() - 1] + dp_last[money.size() - 3]);

    return max(dp_first[money.size() - 1], dp_last[money.size() - 1]);
}

int main() {
    vector<int> money = {10, 2, 2, 100, 2};
    cout << solution(money);
}