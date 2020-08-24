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

int ans;
void util(vi &arr, int pivot, int n)
{
    if (pivot == -1 || pivot == n)
        return;
    int np = -1, min_ = arr[pivot - 1], max_ = arr[pivot - 1];
    for (int i = pivot; i < n; i++)
    {
        max_ = max(max_, arr[i]);
        min_ = min(min_, arr[i]);
        if (arr[i] > arr[i + 1])
        {
            np = i + 1;
            break;
        }
    }
    ans += max_ - min_;
    util(arr, np, n);
}

int solve()
{
    ans = 0;
    int n;
    cin >> n;
    vi arr(n, 0);
    loop(n) cin >> arr[i];
    int count = 0;
    int pivot = -1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < arr[i - 1])
        {
            pivot = i;
            break;
        }
    }

    if (pivot != -1)
    {
        util(arr, pivot, n);
        return ans;
    }
    return 0;
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