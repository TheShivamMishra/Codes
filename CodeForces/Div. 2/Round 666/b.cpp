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
    lli n;
    cin >> n;
    vi arr(n,0);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end());
    lli ans =0;
    lli c=0;
    for(int i=0;i<n;i++)
    {
        if(i==0)
        {
            ans += arr[i]-1;
            continue;
        }
        if(i==1)
        c = arr[i];
        if(i>1)
        {
            cout<<c<<endl;
            lli t = c*c;
            c = t;
            cout<<t<<endl;
            if(arr[i]!=t)
            ans += t - abs(arr[i]);
        }
    }

    return ans;
}

int main()
{

    cout << solve() << '\n';
    return 0;
}