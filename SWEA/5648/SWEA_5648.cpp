#include <deque>
#include <iostream>
#include <unordered_map>

#define MAX_W 2000 * 2

using namespace std;

struct item
{
    int x, y, d, e;
};

int dir[4][2] = {
    {0, 1},
    {0, -1},
    {-1, 0},
    {1, 0},
};

int T;
int N;
int ret;

unordered_map<int, int> m;
unordered_map<int, item> itemList;

int tmpX, tmpY, tmpD, tmpE;

void printItems()
{
    for (auto i : itemList)
    {
        cout << "{" << i.second.x << ", " << i.second.y << "}" << endl;
    }
    cout << endl;
}

int main(int argc, char **argv)
{
    //freopen("sample_input.txt", "r", stdin);
    cin >> T;

    for (int test_case = 1; test_case <= T; ++test_case)
    {
        cin >> N;
        ret = 0;
        itemList.clear();

        for (int count = 0; count < N; count++)
        {
            cin >> tmpX >> tmpY >> tmpD >> tmpE;
            itemList[count] = item{tmpX * 2, tmpY * 2, tmpD, tmpE};
        }

        while (itemList.size() > 1)
        {
            m.clear();
            deque<pair<int, int>> removeList;
            for (auto &i : itemList)
            {
                i.second.x += dir[i.second.d][0];
                i.second.y += dir[i.second.d][1];

                if (i.second.x < -2000 || i.second.x > 2000 || i.second.y < -2000 || i.second.y > 2000)
                {
                    removeList.emplace_back(make_pair(i.first, 0));
                }
                else
                {
                    if (m.find(i.second.y * MAX_W + i.second.x) == m.end())
                    {
                        m[i.second.y * MAX_W + i.second.x] = i.first;
                    }
                    else
                    {
                        removeList.emplace_back(make_pair(m[i.second.y * MAX_W + i.second.x], 1));
                        removeList.emplace_back(make_pair(i.first, 1));
                    }
                }
            }

            for (auto i : removeList)
            {
                if (itemList.find(i.first) != itemList.end())
                {
                    if (i.second == 1)
                        ret += itemList[i.first].e;
                    itemList.erase(i.first);
                }
            }
            //printItems();
        }

        cout << "#" << test_case << " " << ret << endl;
    }
    return 0;
}