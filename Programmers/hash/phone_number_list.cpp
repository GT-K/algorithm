#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool solution(vector<string> phone_book) {
    sort(phone_book.begin(), phone_book.end());

    for (int i = 0; i < phone_book.size() - 1; i++) {
        if (phone_book[i].size() < phone_book[i + 1].size() && phone_book[i + 1].substr(0, phone_book[i].size()).compare(phone_book[i]) == 0) return false;
    }

    return true;
}

int main() {
    vector<vector<string>> stList = {
        {"1", "11", "119", "1196", "97674223", "1195524421"},
        {"123", "456", "789"},
        {"12", "123", "1235", "567", "88"}};

    for (int i = 0; i < 3; i++)
        cout << solution(stList[i]) << endl;
}