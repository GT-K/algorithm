#include <list>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

list<int> q;

void insert_q(int num) {
    if (q.size() > 0) {
        if (num < q.front())
            q.push_front(num);
        else if (num > q.back())
            q.push_back(num);
        else
            for (auto it = q.begin(); it != q.end(); it++)
                if (*it > num) {
                    q.insert(it, num);
                    break;
                }
    } else {
        q.push_back(num);
    }
}

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    for (auto i : operations) {
        int num;
        if (i[0] == 'I') {
            num = stoi(i.substr(2));
            insert_q(num);
        } else {
            if (i[2] == '-') {
                if (q.size() > 0) q.pop_front();
            } else {
                if (q.size() > 0) q.pop_back();
            }
        }
    }

    if (q.size() == 0) {
        return {0, 0};
    } else {
        return {q.back(), q.front()};
    }
}