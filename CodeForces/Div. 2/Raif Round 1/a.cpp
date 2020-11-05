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

int solve()
{
    int x1, y1, x2, y2,t;
    cin >> x1 >> y1 >> x2 >> y2;
    int dist = abs(x1 - x2) + abs(y1 - y2);
    if(x2!=x1)
    t = abs(y2 - y1) / abs(x2 - x1);
    if (t == 1)
        return dist + 2;
    return dist;
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