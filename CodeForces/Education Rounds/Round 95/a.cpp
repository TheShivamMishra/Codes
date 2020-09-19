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
    lli x,y,k;
    cin>>x>>y>>k; 
    lli tsticks = y*k + k;
    // cout<<tsticks<<" "<<endl;
    lli n = (tsticks-1)/(x-1);
    lli an = 1 + n*(x-1);
    if(an<tsticks)n++;
    return n + k;
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