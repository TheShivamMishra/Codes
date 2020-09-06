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
    int n;
    cin >> n;
    vector<lli> arr(n, 0);
    loop(n) cin >> arr[i];

    int i = 0;
    while (i < n)
    {
        if (arr[i] > 0)
        {
            while (arr[i] != 0)
            {
                int j = -1;
                for (j = i + 1; j < n; j++)
                    if (arr[j] < 0)
                        break;
                if (j == n)
                    break;
                int m = min(arr[i], -arr[j]);
                arr[i] -= m;
                arr[j] += m;
            }
        }
        i++;
    }
    // loop(n) cout<<arr[i]<<" ";
    // cout<<endl;
    lli cost = 0;
    i =0;
    while (i < n)
    {
        if (arr[i] < 0)
        {
            while (arr[i] != 0)
            {
                int j = -1;
                for (j = i + 1; j < n; j++)
                    if (arr[j] > 0)
                        break;
                if (j == n)
                    break;
                lli m = min(-arr[i], arr[j]);
                cost += m;
                arr[i] += m;
                arr[j] -= m;
            }
        }
        i++;
    }
    // loop(n) cout<<arr[i]<<" ";
    return cost;
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