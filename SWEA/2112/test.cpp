#include <vector>

using namespace std;

int main()
{
    vector<int> ori;
    vector<int> cpy;

    ori.push_back(1);
    ori.push_back(1);
    ori.push_back(1);
    ori.push_back(1);
    ori.push_back(1);

    cpy = ori;

    ori.push_back(1);
    ori.push_back(1);
    ori.push_back(1);
    ori.push_back(1);
}