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

// int minSteps(vi &arr, int n, int idx, vi &dp)
// {
//     // cout << idx << " ";
//     if (idx >= n - 1 || idx == n - 2)
//         return dp[idx] = (idx >= n - 1) ? 0 : 1;
//     if (dp[idx] != 0)
//         return dp[idx];
//     int ans = 1e9 + 5;
//     if (idx < n - 1 && arr[idx + 1] > arr[idx])
//     {
//         int j = idx + 1, omin = arr[j];
//         while (j < n && arr[idx] < arr[j])
//         {
//             // int ok = true;
//             // for (int i = j - 1; i > idx; i--)
//             // {
//             //     if (arr[j] >= arr[i])
//             //     {
//             //         ok = false;
//             //         break;
//             //     }
//             // }
//             if (omin > arr[j])
//             {
//                 omin = arr[j];
//                 ans = min(ans, minSteps(arr, n, j, dp));
//             }
//             // if (ok)
//             // {
//             // ans = min(ans, minSteps(arr, n, j, dp));
//             // cout << idx << " " << j << endl;
//             // }
//             j++;
//         }

//         if (j != idx + 1 && j < n)
//             ans = min(ans, minSteps(arr, n, j, dp));
//     }
//     else if (idx < n - 1 && arr[idx + 1] < arr[idx])
//     {
//         int j = idx + 1, omax = arr[j];
//         while (j < n && arr[j] < arr[idx])
//         {
//             //     int ok = true;
//             //     for (int i = j - 1; i > idx; i--)
//             //     {
//             //         if (arr[j] <= arr[i])
//             //         {
//             //             ok = false;
//             //             break;
//             //         }
//             //     }
//             //     if (ok)
//             //         ans = min(ans, minSteps(arr, n, j, dp));
//             if (omax < arr[j])
//             {
//                 omax = arr[j];
//                 ans = min(ans, minSteps(arr, n, j, dp));
//             }
//             j++;
//         }

//         if (j != idx + 1 && j < n)
//             ans = min(ans, minSteps(arr, n, j, dp));
//     }
//         ans = min(ans, minSteps(arr, n, idx + 1, dp));
//     // cout<<ans<<endl;
//     return dp[idx] = ans + 1;
// }

// void solve()
// {
//     int n;
//     cin >> n;
//     vi arr(n, 0), dp(n, 0);
//     loop(n) cin >> arr[i];
//     cout << minSteps(arr, n, 0, dp) << "\n";
//     // loop(n) cout << dp[i] << " ";
//     // cout << endl;
// }

// int main()
// {
//     solve();
//     return 0;
// }

void solve(){
    int n;
    cin>>n;
    
}

int main()
{
    solve();
    return 0;
}