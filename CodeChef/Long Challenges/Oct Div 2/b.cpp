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
    lli n, k;
    cin >> n >> k;
    lli qi = 0, carry = 0;
    for (lli i = 0; i < n; i++)
    {
        cin >> qi;
        if ((qi + carry) < k)
            return i+1;
        carry += qi;
        carry = ((carry - k) <= 0 ? 0 : (carry - k));
    }
    lli a = carry / k;
    return n + a + 1;
}

int main()
{
    lli t;
    cin >> t;
    while (t--)
    {
        cout << solve() << '\n';
    }
    return 0;
}