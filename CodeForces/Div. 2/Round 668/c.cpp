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
    int n, m;
    cin >> n >> m;
    string str;
    cin >> str;

    for (int i = 0; i <= n - m; i++)
    {
        int z = 0, o = 0, q = 0;
        for (int j = i; j < i + m; j++)
        {
            if (str[j] == '?')
                q++;
            else if (str[j] == '0')
                z++;
            else
                o++;
        }
        if (o == m || z == m || q!= m - z+o)
            return "No";
        
    }

    return "Yes";
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