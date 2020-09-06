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

void solve()
{
    int n, x, y;
    cin >> n >> x >> y;

    int dist = y - x, steps = 0;
    int d = 0;
    int ok = 0;
    for (int i = 1; i <= dist && !ok; i++)
    {
        // cout<<i;
        if (dist % i == 0)
        {
            steps = dist / i;
            // cout<<steps<<" "<<i<<" ";
            if (steps < n)
            {
                // cout<<i<<endl;
                d = max(d, i);
                ok = true;
            }
        }
    }
    steps = dist / d;
    cout << d << endl;
    int t = (n - 1) * d;
    if (t >= y)
    {
        int a = 1;
        int check = 
        if(a)
        loop(n)
        {
            cout << a << " ";           
            a += d;
        }
    }
    else
    {
        int a = y - t;
        loop(n)
        {
            cout << a << " ";
            a += d;
        }
    }
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