#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

string solution(vector<string> participants, vector<string> completions) {
    unordered_map<string, int> nameCountList;

    for (auto participant : participants)
        nameCountList[participant]++;
    for (auto completion : completions)
        nameCountList[completion]--;

    for (auto nameCount : nameCountList)
        if (nameCount.second != 0) return nameCount.first;
}

int main() {
    vector<vector<string>> participantList = {{"leo", "kiki", "eden"},
                                              {"marina", "josipa", "nikola", "vinko", "filipa"},
                                              {"mislav", "stanko", "mislav", "ana"}};
    vector<vector<string>> completeList = {{"kiki", "eden"},
                                           {"marina", "josipa", "nikola", "filipa"},
                                           {"mislav", "stanko", "ana"}};

    for (int i = 0; i < 3; i++)
        cout << solution(participantList[i], completeList[i]) << endl;
}

// #include <string>
// #include <unordered_map>
// #include <vector>

// using namespace std;

// string solution(vector<string> participant, vector<string> completion)
// {
//     string answer = "";
//     unordered_map<string, int> list;
//     for (auto i : participant)
//         list[i]++;
//     for (auto i : completion)
//         list[i]--;
//     for (auto i : list)
//         if (i.second > 0)
//             return i.first;
// }