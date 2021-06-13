#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

int T;
int D, W, K;
int ret;

int m[13][20];
int testM[13][20];
vector<vector<int>> rowList;
vector<vector<int>> abList;

void printMap()
{
    for (int r = 0; r < D; r++)
    {
        for (int c = 0; c < W; c++)
            cout << testM[r][c];
        cout << endl;
    }
    cout << endl;
}

int pass()
{
    for (int c = 0; c < W; c++)
    {
        int max_count = 0;
        int tmp = 1;
        for (int r = 1; r < D; r++)
        {
            if (testM[r][c] == testM[r - 1][c])
                tmp++;
            else
                tmp = 1;
            if (tmp == K)
                break;
        }
        if (tmp < K)
            return 0;
    }
    //printMap();
    return 1;
}

void assertion(int passNum, vector<vector<int>>::iterator row, vector<vector<int>>::iterator ab)
{
    memcpy(testM, m, sizeof(testM));
    for (int count = 0; count < passNum; count++)
    {
        for (int c = 0; c < W; c++)
        {
            testM[*((*row).begin() + count)][c] = *((*ab).begin() + count);
        }
    }
    //printMap();
}

void chooseAB(int makeN, vector<int> v)
{
    if (makeN == v.size())
        abList.emplace_back(v);
    else
    {
        for (int i = 0; i < 2; i++)
        {
            v.emplace_back(i);
            chooseAB(makeN, v);
            v.pop_back();
        }
    }
}

void chooseRow(int makeN, int n, vector<int> v)
{
    if (makeN == v.size())
        rowList.emplace_back(v);
    else
    {
        for (int i = n + 1; i < D; i++)
        {
            v.emplace_back(i);
            chooseRow(makeN, i, v);
            v.pop_back();
        }
    }
}
int main(int argc, char **argv)
{
    //freopen("3_1.txt", "r", stdin);
    cin >> T;

    for (int test_case = 1; test_case <= T; ++test_case)
    {
        cin >> D >> W >> K;
        memset(m, 0, sizeof(m));
        for (int r = 0; r < D; r++)
            for (int c = 0; c < W; c++)
                cin >> m[r][c];
        ret = D;
        if (K == 1)
        {
            cout << "#" << test_case << " " << 0 << "\n";
            continue;
        }

        memcpy(testM, m, sizeof(testM));
        if (pass())
            cout << "#" << test_case << " " << 0 << "\n";

        else
        {
            for (int passNum = 1; passNum < D; passNum++)
            {
                rowList.clear();
                abList.clear();
                chooseRow(passNum, -1, vector<int>());
                chooseAB(passNum, vector<int>());

                for (auto iterRow = rowList.begin(); iterRow != rowList.end(); iterRow++)
                {
                    for (auto iterAB = abList.begin(); iterAB != abList.end(); iterAB++)
                    {
                        assertion(passNum, iterRow, iterAB);
                        if (pass())
                        {
                            ret = passNum;
                            goto next;
                        }
                    }
                }
            }
        next:
            cout << "#" << test_case << " " << ret << "\n";
        }
    }
    return 0; //정상종료시 반드시 0을 리턴해야합니다.
}
