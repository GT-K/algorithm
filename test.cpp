#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

int main() {
    vector<int> v = {1, 2, 3, 4, 5, 6};

    v[v.size() - 1] = 0;

    for (auto i : v)
        cout << i << "\t";
}