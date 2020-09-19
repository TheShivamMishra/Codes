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
    int one = 0;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        if (a)
            one++;
    }
    int zero = n - one;
    if (zero >= n / 2)
    {
        cout << zero << "\n";
        for (int i = 0; i < zero; i++)
            cout << 0 << " ";
    }
    else
    {
        if(one&1)
        one--;
        cout << one << "\n";
        for (int i = 0; i < one; i++)
            cout << 1 << " ";
    }
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