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
    string str, t = "atcoder";
    cin >> str;
    int n = str.size();
    if (n < 7)
        return -1;

    if (str[0] > t[0])
        return 0;
    int i = 0;
    while (i < n && str[i] <= t[i])
        i++;

    int k = i;
    while (k < n && str[k] <= t[i])
        k++;
    cout << k << " " << i << endl;
    return k - i + 1;
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