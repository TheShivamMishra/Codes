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

void joesphus(int n, int k, int x, vb &vis)
{
    if (vis[x])
        return;
    vis[x] = true;
    joesphus(n, k, (x + k) % n, vis);
}

string solve()
{
    int n, k, x, y;
    cin >> n >> k >> x >> y;
    vector<bool> vis(n, false);
    joesphus(n, k, x, vis);
    if (vis[y])
        return "YES";
    return "NO";
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