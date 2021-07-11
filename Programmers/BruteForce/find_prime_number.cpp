#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <unordered_set>

using namespace std;

int judge(int number)
{
    if (number <= 1) return 0;
    for (int i = 2; i <= sqrt(number); i++)
        if (number % i == 0) return 0;
    return 1;
}

int solution(string numbers) {
    unordered_set<int> s;
    int answer = 0;
    sort(numbers.begin(), numbers.end());

    do {
        for (int i = 1; i <= numbers.length(); i++) s.insert(stoi(numbers.substr(0, i)));
    } while (next_permutation(numbers.begin(), numbers.end()));

    for (auto item : s)
        answer += judge(item);

    return answer;
}
// int solution(string numbers) {
//     unordered_set<int> s;
//     int answer = 0;
//     vector<int> number_list;
//     for (int i = 0; i < numbers.length(); i++) number_list.emplace_back(numbers[i] - '0');
//     sort(number_list.begin(), number_list.end());

//     do {
//         for (int i = number_list.size() - 1; i >= 0; i--) {
//             vector<int> v(i, 0);
//             for (int j = 1; j <= number_list.size() - i; j++) v.push_back(1);

//             do {
//                 string test_num = "";
//                 for (int j = 0; j < v.size(); j++) if (v[j]) test_num.push_back(number_list[j] + '0');
//                 s.insert(stoi(test_num));
//             } while (next_permutation(v.begin(), v.end()));
//         }
//     } while (next_permutation(number_list.begin(), number_list.end()));

//     for(auto item : s)
//         answer += judge(item);

//     return answer;
// }

int main()
{
    vector<string> numbers_list = {"17", "011"};

    for (auto item : numbers_list)
        cout << solution(item) << endl;
} 
// #include <algorithm>
// #include <iostream>
// #include <string>
// #include <vector>
// using namespace std;

// int judge(string);
// void dfs(int);

// string numbers;
// string answer_arr;
// vector<int> num_arr;
// vector<int> visited;

// int answer = 0;
// int nsize;

// using namespace std;

// int solution(string tmp_numbers) {
//     numbers = tmp_numbers;
//     nsize = numbers.size();
//     visited.assign(numbers.size(), 0);

//     dfs(0);

//     return answer;
// }

// void dfs(int n) {
//     if (n == numbers.size()) {
//     } else {
//         for (int i = 0; i < numbers.size(); i++) {
//             if (visited[i] == 0) {
//                 answer_arr.push_back(numbers[i]);
//                 visited[i] = 1;
//                 answer += judge(answer_arr);
//                 dfs(n + 1);
//                 answer_arr.pop_back();
//                 visited[i] = 0;
//             }
//         }
//     }
// }

// int judge(string n) {
//     int num = stoi(n);
//     int count = 0;
//     if (find(num_arr.begin(), num_arr.end(), num) == num_arr.end()) {
//         num_arr.push_back(num);
//         for (int i = 2; i <= num; i++)
//             if (num % i == 0) count++;
//         if (count == 1) return 1;
//     }
//     return 0;
// }