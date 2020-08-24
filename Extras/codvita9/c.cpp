#include "bits/stdc++.h"
#define vi vector<int>
#define vb vector<bool>
#define lli long long int
#define vvi vector<vector<int>>
#define loop(n) for (int i = 0; i < n; i++)
using namespace std;

auto SpeedUp = []() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
vector<pair<int, int>> path;
int currx = 1, curry = 1;

void rotateDira()
{
    if (currx == 1 && curry == 1)
    {
        currx = 1;
        curry = -1;
    }
    else if (currx == 1 && curry == -1)
    {
        currx = -1;
        curry = -1;
    }
    else if (currx == -1 && curry == -1)
    {
        currx = -1;
        curry = 1;
    }
    else
    {
        currx = 1;
        curry = 1;
    }
}

void rotateDirc()
{
    if (currx == 1 && curry == 1)
    {
        currx = -1;
        curry = 1;
    }
    else if (currx == 1 && curry == -1)
    {
        currx = 1;
        curry = 1;
    }
    else if (currx == -1 && curry == -1)
    {
        currx = 1;
        curry = -1;
    }
    else
    {
        currx = -1;
        curry = -1;
    }
}

int infect;
void dfs(vector<vector<char>> &board, int sr, int sc, int &boundryCount)
{
    if (board[sr][sc] == '*')
    {
        path.push_back({sr, sc});
            boundryCount++;
        
        if (boundryCount == 2)
            return;

        vector<vector<int>> dir = {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
        for (int d = 0; d < 4; d++)
        {
            if (currx != dir[d][0] && curry != dir[d][1])
            {

                int nr = dir[d][0] + sr;
                int nc = dir[d][1] + sc;
                // cout << nr << nc << endl;
                if (nr >= 0 && nr <= 8 && nc >= 0 && nc < 20)
                {

                    currx = dir[d][0];
                    curry = dir[d][1];
                    break;
                }
            }
        }
    }

    if (boundryCount < 2 && board[sr][sc] == 'a')
    {
        infect++;
        board[sr][sc] = '-';
        rotateDira();
    }
    if (boundryCount < 2 && board[sr][sc] == 'c')
    {
        infect++;
        board[sr][sc] = '-';
        rotateDirc();
    }
    if (boundryCount < 2)
    {
        path.push_back({sr, sc});
        int nr = currx + sr;
        int nc = curry + sc;
        dfs(board, nr, nc, boundryCount);
    }
}

void solve()
{
    path.clear();
    path.resize(0);
    currx = 1;
    curry = 1;
    infect = 0;
    vector<vector<char>> board(9, vector<char>(20, '#'));
    int totalCitizen = 0;
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 20; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 'a' || board[i][j] == 'c')
                totalCitizen++;
        }

    int boundryCount = 0;
    dfs(board, 1, 1, boundryCount);
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            cout << board[i][j];
        }
        cout << endl
             << endl;
    }
    for (auto e : path)
        cout << e.first << e.second << endl;
    cout << "safe=" << totalCitizen - infect << endl;
    cout << "infected=" << infect << endl;
}
int main()
{
    solve();
    return 0;
}