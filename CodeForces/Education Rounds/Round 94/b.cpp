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
    int mycapcity, fcapacity;
    cin >> mycapcity >> fcapacity;
    int nsword, nwar, wsword, wwar;
    cin >> nsword >> nwar >> wsword >> wwar;
    lli tweight = mycapcity + fcapacity;
    int count = 0;
    if (tweight >= (nsword * wsword + nwar * wwar))
        return nsword + nwar;
    // cout<<tweight<<endl;
    while (tweight)
    {
        while (nsword != 0 && wsword <= wwar && tweight >= wsword)
        {
            nsword--;
            tweight -= wsword;
            count++;
        }
        while (nwar != 0 && tweight >= wwar)
        {
            nwar--;
            tweight -= wwar;
            count++;
        }
        if (nwar == 0 && tweight<wsword)
            break;
        if(nsword ==0 && tweight<wwar)
        break;    
        if (tweight < wwar && tweight < wsword)
            break;
    }

    return count;
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