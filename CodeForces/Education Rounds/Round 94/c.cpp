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

bool compare(string& str,string& temp)
{
    int zero =0;
    int n = str.size();
    for(int i =0;i<n;i++)
     if(str[i]=='0') zero++;

    for (int i = 0; i < n; i++)
        if (temp[i] == '0')
            zero--;
    return zero==0;        
}

void solve()
{
    int x;
    string str;
    cin >> str;
    cin >> x;
    int n = str.size();
    string ans;
    for(int i=0;i<n;i++) ans+='0';
    for (int i = 0; i < n; i++)
    {
        if(str[i]=='1')
        if (i - x >= 0)
            ans[i-x] = '1';
        else if (i + x < n)
            ans[i+x] = '1';
    }

    // string temp;
    // for (int i = 0; i < n; i++)
    // {
    //     if (i - x >= 0 && ans[i - x] == '1')
    //         temp += '1';
    //     else if (i + x < n && ans[i + x] == '1')
    //         temp += '1';
    //     else
    //         temp += '0';
    // }
    if (ans!=str)
        cout << ans;
    else
        cout << "-1";
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
        cout << '\n';
    }
    return 0;
}