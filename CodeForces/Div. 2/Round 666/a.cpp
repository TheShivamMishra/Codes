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
    string str;
    vi freq(256, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> str;
        int l = str.size();
        for (int i = 0; i < l; i++)
            freq[str[i]]++;
    }

    for (int i = 0; i < 256; i++)
        if (freq[i] != 0 && freq[i] % n != 0)
        {
            cout << "NO";
            return;
        }

    cout << "YES";
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