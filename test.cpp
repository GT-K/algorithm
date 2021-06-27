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
    map<int, int> Map;
    Map[1] = 10;
    Map[2] = 20;
    Map[3] = 30;
    Map[4] = 40;

    for (auto iter : Map)
        cout << iter.second;
    Map[1] *= -1;
    Map[2] *= -1;
    Map[3] *= -1;
    Map[4] *= -1;
    for (auto iter : Map)
        cout << iter.second;
}