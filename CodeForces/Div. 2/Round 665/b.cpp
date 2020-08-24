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

void maxSum(lli x1, lli y1, lli z1, lli x2, lli y2, lli z2, lli &sum)
{
    if (x1 <0 || y1 <0 || z1 <0)
        return;
    cout<<x1<<y1<<z1<<endl;    
    if (z1 > 0)
    {
        if (x2 > 0)
        {
            sum += 2;
            maxSum(x1, y1, z1 - 1, x2 - 1, y2, z2, sum);
        }
        else if (y2 > 0)
        {
            sum += 2;
            maxSum(x1, y1, z1 - 1, x2, y2 - 1, z2, sum);
        }
        else if(z2>0)
            maxSum(x1, y1, z1 - 1, x2, y2, z2 - 1, sum);
    }
    else if (y1 > 0)
    {
        if (x2 > 0)
        {
            sum += 1;
            maxSum(x1, y1 - 1, z1, x2 - 1, y2, z2, sum);
        }
        else if (y2 > 0)
        {
            maxSum(x1, y1 - 1, z1 - 1, x2, y2 - 1, z2, sum);
        }
        else if (z2 > 0)
        {
            sum -= 2;
            maxSum(x1, y1 - 1, z1, x2, y2, z2 - 1, sum);
        }
    }
    else if(x1 >0)
    {
        if (x2 > 0)
        {
            maxSum(x1 - 1, y1, z1, x2 - 1, y2, z2, sum);
        }
        else if (y2 > 0)
        {
            sum -= 1;
            maxSum(x1 - 1, y1, z1, x2, y2 - 1, z2, sum);
        }
        else if (z2 > 0)
        {
            sum -= 2;
            maxSum(x1 - 1, y1, z1, x2, y2, z2 - 1, sum);
        }
    }
}

lli solve()
{
    lli x1, y1, z1, x2, y2, z2;
    cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
    lli sum = 0;
    maxSum(x1, y1, z1, x2, y2, z2, sum);
    return sum;
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