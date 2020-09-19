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

int minSkips(vi& arr,int idx,int n,int myTurn,vector<vector<int>>& dp)
{
    if(idx==n) return 0;
    if(dp[idx][myTurn]!=-1) return dp[idx][myTurn];
    if(myTurn)
    {
         if(idx+1!=n)
         {
            return dp[idx][myTurn]= min(minSkips(arr,idx+2,n,false,dp),minSkips(arr,idx+1,n,false,dp));
         }
         return dp[idx][myTurn] =  minSkips(arr,idx+1,n,false,dp);
    }else{
       
        if(idx+1!=n)
        {
            if(arr[idx]==1 && arr[idx+1]==1)
                return dp[idx][myTurn] = min(minSkips(arr, idx + 2, n, true, dp) + 2, minSkips(arr, idx + 1, n, true, dp) + 1);
            else if(arr[idx]==0 && arr[idx+1]==1)
                return dp[idx][myTurn] = min(minSkips(arr, idx + 2, n, true, dp) + 1, minSkips(arr, idx + 1, n, true, dp));
            else if(arr[idx]==1 && arr[idx+1]==0)
                return dp[idx][myTurn] = min(minSkips(arr, idx + 2, n, true, dp) + 1, minSkips(arr, idx + 1, n, true, dp) + 1);
            else
                return dp[idx][myTurn]  = min(minSkips(arr, idx + 2, n, true, dp), minSkips(arr, idx + 1, n, true, dp));
        }
        else {
            return dp[idx][myTurn] = arr[idx] == 0 ? minSkips(arr, idx + 1, n, true, dp) : minSkips(arr, idx + 1, n, true, dp)+1;
        }
    }
}

int solve()
{
    int n;
    cin>>n;
    vi arr(n,0);
    loop(n) cin>>arr[i];
    
    vector<vector<int>> dp(n,vector<int>(2,-1));
    return minSkips(arr,0,n,false,dp);
}

int main()
{
    int t;
    cin>>t;
    while (t--) {
        cout<<solve()<<'\n';
    }
    return 0;
}