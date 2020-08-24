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
    lli n, k;
    cin >> n >> k;
    vi arr(n, 0);
    int max_ = INT_MIN;
    loop(n)
    {
        cin >> arr[i];
        max_ = max(max_, arr[i]);
    }

    vi Evenarr(n,0),Oddarr(n,0);
    int emax = INT_MIN,odmax = INT_MIN;
    for(int i=0;i<n;i++)
    {
        Oddarr[i] = max_ - arr[i];
        odmax = max(odmax,Oddarr[i]);
    }

    for(int i=0;i<n;i++)
    {
        Evenarr[i] = odmax - Oddarr[i];
    }

    if (k & 1)
    {
        for (int i = 0; i < n; i++)
            cout << Oddarr[i] << " ";
        cout << endl;
    }
    else 
    {
        for (int i = 0; i < n; i++)
            cout << Evenarr[i] << " ";
        cout << endl;
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}