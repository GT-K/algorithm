#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;

    unordered_map<string, vector<string>> categorizedClothes;

    for (auto cloth : clothes) {
        categorizedClothes[cloth[1]].emplace_back(cloth[0]);
    }

    for (auto clothes : categorizedClothes) {
        answer *= clothes.second.size() + 1;
    }

    return answer - 1;
}

int main() {
    vector<vector<vector<string>>> stList = {
        {{"yellowhat", "headgear"}, {"bluesunglasses", "eyewear"}, {"green_turban", "headgear"}},
        {{"crowmask", "face"}, {"bluesunglasses", "face"}, {"smoky_makeup", "face"}}};

    for (int i = 0; i < 2; i++)
        cout << solution(stList[i]) << endl;
}