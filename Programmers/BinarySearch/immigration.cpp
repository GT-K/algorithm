#include <string>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;

    long long left = 0;
    long long right = *max_element(times.begin(), times.end()) * (long long)n;

    long long sum = 0;
    while(left <= right)
    {
        long long mid = (left + right) / 2;

        sum = 0;
        for(auto time : times) sum += mid / time;

        if (sum >= n) {
            answer = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return answer;
}

int main()
{
    int n = 3;
    vector<int> times = {1,2,3};

    solution(n, times);
}