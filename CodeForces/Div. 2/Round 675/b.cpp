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

lli solve()
{
    int n, m;
    cin >> n >> m;
    vvi matrix(n, vi(m, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> matrix[i][j];

    lli ans = 1e12;
    for (int i = 0; i < n;i++)
    {
        for (int j = 0; j < m; j++)
        {
            lli sum = 0;
            int ele = matrix[i][j];
            for (int l = 0; l < n; l++)
            {
                for (int k = 0; k < m; k++)
                    sum += abs( matrix[l][k] - ele);
            }
            ans = min(ans, sum);
        }
    }
    return ans;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cout << solve() << '\n';
    }
    return 0;
}