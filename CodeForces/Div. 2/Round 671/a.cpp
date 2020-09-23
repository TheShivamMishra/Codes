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
    int num;
    cin >> num;
    // cout<<num;
    int mask = 0;
    if (n & 1)
    {
        while (num!=0)
        {
            int c = num % 10;
            if (c & 1)
                return 1;
            num /= 100;
        }

        return 2;
    }
    else
    {
        while (num!=0)
        {
            int c = num % 10;
            if (c % 2 == 0)
                return 2;
            num /= 100;
        }
        return 1;
    }
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