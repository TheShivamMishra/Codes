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

string solve()
{
    int n;
    cin >> n;
    string str, ans;
    cin >> str;
    if(n==1) return str;
    int m = 2*n -1;
    // for(int i=0;i<n;i++)
    // ans += str[i];
    // int set = 0;
    // cout<<ans<<endl;
    ans+=str[0];
    for(int i=1;i<n;i++)
    {
        int idx =0;
        for(int j = i;j<n;j++)
        {
            ans+=str[j];
        }
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