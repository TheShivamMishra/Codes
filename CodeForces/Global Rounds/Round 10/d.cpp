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
    int n;
    cin >> n;
    string str;
    cin >> str;
    int ans = 0;
    int i = 0, j = n - 1;
    if (str[i] == 'L' && str[j] == 'L')
    {
        ans++;
        str[j] ='R';
        i++;
        j++;
    }
    while (i < j)
    {
        if(str[i]=='R')
        {
           if(str[i+1]=='R')
           {
               ans++;
               j+=2;
           }
        }else
        {
            /* code */
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