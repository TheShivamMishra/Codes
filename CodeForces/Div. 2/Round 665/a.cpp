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

int solve()
{
    int n, k;
    cin >> n >> k;
    int ans = 1e9;
    if(k==n)
    return 0;
   
   int rlim = (n+k)/2;
   for(int i=0;i<=n/2;i++)
   {
       int temp = abs(k - abs(2*i-n));
       if(temp<ans)
       ans = min(ans,temp);
       else 
       break;
   }

   return ans;
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