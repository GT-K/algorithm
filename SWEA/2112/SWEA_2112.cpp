#include <algorithm>
#include <array>
#include <deque>
#include <iostream>

#define MAX_W 20
#define MAX_D 13

using namespace std;

struct item
{
    int count;
    array<int, MAX_D> visited;
    array<array<int, MAX_W>, MAX_D> m;
};

int T;
int D, W, K;
int ret;

array<int, MAX_D> tmpVisited;

array<array<int, MAX_W>, MAX_D> m;
array<array<int, MAX_W>, MAX_D> tmpM;

deque<item> q;
item cur;

void printMap(array<array<int, 20>, 13> m)
{
    for (int r = 0; r < D; r++)
    {
        for (int c = 0; c < W; c++)
            cout << m[r][c];
        cout << endl;
    }
    cout << endl;
}

int pass(array<array<int, 20>, 13> &m)
{
    for (int c = 0; c < W; c++)
    {
        int tmp = 1;
        for (int r = 1; r < D; r++)
        {
            if (m[r][c] == m[r - 1][c])
                tmp++;
            else
                tmp = 1;
            if (tmp == K)
                break;
        }
        if (tmp < K)
            return 0;
    }
    return 1;
}

int main(int argc, char **argv)
{
    freopen("sample_input.txt", "r", stdin);
    cin >> T;

    for (int test_case = 1; test_case <= T; ++test_case)
    {
        cin >> D >> W >> K;
        q.clear();
        for (int r = 0; r < D; r++)
            for (int c = 0; c < W; c++)
                cin >> m[r][c];

        if (K == 1)
        {
            cout << "#" << test_case << " " << 0 << endl;
            continue;
        }

        q.emplace_back(item{0, array<int, MAX_D>(), m});

        while (!q.empty())
        {
            cur = q.front();
            q.pop_front();

            ret = cur.count;

            if (pass(cur.m))
                break;
            else
            {
                int count = 0;
                for (auto iter = cur.visited.begin(); iter != cur.visited.end(); iter++, count++)
                {
                    tmpM = cur.m;
                    if ((*iter) == 0)
                    {
                        cur.visited[count] = 1;
                        for (int ab = 0; ab < 2; ab++)
                        {
                            for (int c = 0; c < W; c++)
                                tmpM[count][c] = ab;
                            q.emplace_back(item{cur.count + 1, cur.visited, tmpM});
                        }
                    }
                }
            }
        }
        cout << "#" << test_case << " " << ret << endl;
    }
    return 0; //정상종료시 반드시 0을 리턴해야합니다.
}
