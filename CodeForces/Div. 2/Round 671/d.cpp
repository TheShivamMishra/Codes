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
    int n, count = 0;
    cin >> n;
    vi arr(n);
    loop(n) cin >> arr[i];
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i += 2)
        if (i + 1 < n)
        {
            swap(arr[i], arr[i + 1]);
            count++;
        }
    int ans = (n & 1) ? count : count - 1;
    cout<<ans<<"\n";
    loop(n) cout<<arr[i]<<" ";
    cout<<endl;
}

int main()
{
    solve();
    cout << "\n";
    return 0;
}