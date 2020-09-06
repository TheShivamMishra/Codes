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
    lli a, b, x, y, n;
    cin >> a >> b >> x >> y >> n;
    lli t1 = a, t2 = b, N = n;
    if (a - x <= n)
    {
        n -= (a - x);
        a = x;
    }
    else
    {
        a -= n;
        n = 0;
    }

    if (b - y <= n)
    {
        n -= b - y;
        b = y;
    }
    else
    {
        b -= n;
        n = 0;
    }

    // cout<<a<<" "<<b<<endl;

    if (t2 - y <= N)
    {
        N -= (t2 - y);
        t2 = y;
    }
    else
    {
        t2 -= N;
        N = 0;
    }

    if (t1 - x <= N)
    {
        N -= t1 - x;
        t1 = x;
    }
    else
    {
        t1 -= N;
        N = 0;
    }

    // cout<<a<<" "<<b<<endl;
    return a * b < t1 * t2 ? a * b : t1 * t2;
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