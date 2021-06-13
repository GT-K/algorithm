#include <iostream>
#include <map>
#include <string>
using namespace std;

void print(map<int, string> Target_Map)
{
    for (auto i : Target_Map)
        cout << "Key->" << i.first << ", Value->" << i.second << "   ";
    cout << endl;
}

int main()
{
    map<int, string> Map;
    Map[1] = "First";
    Map[2] = "Second";
    Map[3] = "Third";
    Map[4] = "Fourth";

    print(Map);
    Map.erase(0);
    print(Map);
    Map.erase(Map.begin());
    print(Map);
    Map.erase(Map.begin(), Map.end());
    print(Map);
}