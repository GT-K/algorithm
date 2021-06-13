#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>

using namespace std;

enum DIR
{
    UP = 0,
    RIGHT,
    DOWN,
    LEFT,
};

DIR shape[6][4] = {
    {UP, RIGHT, DOWN, LEFT},
    {DOWN, LEFT, RIGHT, UP},
    {RIGHT, LEFT, UP, DOWN},
    {LEFT, DOWN, UP, RIGHT},
    {DOWN, UP, LEFT, RIGHT},
    {DOWN, LEFT, UP, RIGHT},
};

int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int T;
int N;
int m[100][100];
int result;
int test_case;
unordered_map<int, vector<pair<int, int>>> holeList;

int initR, initC, initD;

int simulation(int r, int c, int d);

int main(int argc, char **argv)
{
    freopen("sample_input.txt", "r", stdin);
    cin >> T;

    for (test_case = 1; test_case <= T; ++test_case)
    {
        cin >> N;
        holeList.clear();
        for (int r = 0; r < N; r++)
            for (int c = 0; c < N; c++)
            {
                cin >> m[r][c];
                if (m[r][c] >= 6)
                    holeList[m[r][c]].push_back(make_pair(r, c));
            }
        result = 0;

        for (int r = 0; r < N; r++)
            for (int c = 0; c < N; c++)
                for (int d = 0; d < 4; d++)
                {
                    if (m[r][c] != 0)
                        break;
                    initR = r;
                    initC = c;
                    initD = d;
                    //cout << "S(" << r << ", " << c << ", " << d << ")" << endl;
                    result = max(simulation(r, c, d), result);
                }

        cout << "#" << test_case << " " << result << endl;
    }
    return 0;
}

int simulation(int r, int c, int d)
{
    int ret = 0;
    do
    {
        if (r == -1 && d == 0)
        {
            d = 2;
            ret++;
        }
        else if (r == N && d == 2)
        {
            d = 0;
            ret++;
        }
        else if (c == -1 && d == 3)
        {
            d = 1;
            ret++;
        }
        else if (c == N && d == 1)
        {
            d = 3;
            ret++;
        }
        else
        {
            if (m[r][c] >= 1 && m[r][c] <= 5)
            {
                d = shape[m[r][c]][d];
                ret++;
            }
            else if (m[r][c] >= 6)
            {
                int tmpR, tmpC;
                if (holeList[m[r][c]][0].first == r && holeList[m[r][c]][0].second == c)
                {
                    tmpR = holeList[m[r][c]][1].first;
                    tmpC = holeList[m[r][c]][1].second;
                }
                else
                {
                    tmpR = holeList[m[r][c]][0].first;
                    tmpC = holeList[m[r][c]][0].second;
                }
                r = tmpR;
                c = tmpC;
            }
        }

        r = r + dir[d][0];
        c = c + dir[d][1];

        //cout << initR << ", " << initC << ", " << initD << " (" << r << ", " << c << ", " << d << ")" << endl;

        if ((r == initR && c == initC) || m[r][c] == -1)
            break;
    } while (true);

    return ret;
}
