#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
    string answer = "";

    for (int i = 0; i < new_id.size(); i++) {
        auto tmpC = new_id[i];
        if (tmpC >= 'A' && tmpC <= 'Z') new_id[i] += -'A' + 'a';
    }

    for (int i = 0; i < new_id.size(); i++) {
        auto tmpC = new_id[i];
        auto flag = !((tmpC >= 'a' && tmpC <= 'z') || (tmpC >= '0' && tmpC <= '9') || tmpC == '-' || tmpC == '_' || tmpC == '.');
        if (flag) {
            new_id.erase(i--, 1);
        }
    }

    for (int i = 1; i < new_id.size(); i++) {
        auto tmpC = new_id[i];
        auto flag = tmpC == '.' && new_id[i - 1] == '.';
        if (flag) {
            new_id.erase(i--, 1);
        }
    }

    if (new_id[new_id.size() - 1] == '.')
        new_id.erase(new_id.size() - 1, 1);
    if (new_id[0] == '.')
        new_id.erase(0, 1);

    if (new_id.size() == 0)
        new_id = "a";

    if (new_id.size() >= 16)
        new_id.erase(15);
    if (new_id.back() == '.')
        new_id.pop_back();

    while (new_id.size() <= 2) {
        new_id.push_back(new_id.back());
    }

    return new_id;
}

int main() {
    solution("abcdefghijklmn.p");
}