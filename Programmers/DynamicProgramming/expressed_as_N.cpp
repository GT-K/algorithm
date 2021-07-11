//#include <string>
#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

int solution(int N, int number) {
    int answer = 0;
    unordered_map<int, set<int>> m;

    m[1] = {-N, N};

    int count = 2;
    while (count < 9) {
        int tmp_num = N;
        for (int i = 1; i < count; i++) {
            tmp_num *= 10;
            tmp_num += N;
        }
        m[count].insert(tmp_num);
        m[count].insert(-tmp_num);

        for (int i = 1; i <= count / 2; i++) {
            for (auto item1 : m[count - i]) {
                for (auto item2 : m[i]) {
                    int sum = item1 + item2;
                    int sub = item1 > item2 ? item1 - item2 : item2 - item1;
                    int mul = item1 * item2;
                    int div1 = item2 ? item1 / item2 : 0;
                    int div2 = item1 ? item2 / item1 : 0;
                    if (sum == number || sub == number || mul == number || div1 == number || div2 == number)
                        return count;

                    m[count].insert(sum); m[count].insert(-sum);
                    m[count].insert(sub); m[count].insert(-sub);
                    m[count].insert(mul); m[count].insert(-mul);
                    m[count].insert(div1); m[count].insert(-div1);
                    m[count].insert(div2); m[count].insert(-div2);
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