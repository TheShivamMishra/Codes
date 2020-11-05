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

void solve()
{
    int n;
    cin >> n;
    if (n == 1)
    {
        cout << 1;
        return;
    }
    if ((n & (n - 1)) == 0)
    {
        cout << -1;
        return;
    }
    if (n >= 3)
    {
        cout << 2 << " " << 3 << " " << 1 << " ";
        if (n == 3)
            return;
    }
    int i = 4;
    while (i <= n)
    {
        if ((i & (i - 1)) == 0)
        {
            cout << i + 1 << " " << i << " ";
            i += 2;
            continue;
        }
        cout << i << " ";
        i++;
    }
    return;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
        cout << '\n';
    }
    return 0;
}