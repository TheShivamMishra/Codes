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
    int a,b;
    cin>>a>>b;
    int m = abs(a-b);
    int sum = m/10;
    if(m%10!=0)
    return sum+1;
    return sum;
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