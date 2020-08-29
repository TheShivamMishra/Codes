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

// Read Me :
/*
This whole file contains different dp space and time optimized solution of multiple questions.
*/

void display(vi &dp)
{
    for (int ele : dp)
        cout << ele << " ";
    cout << endl;
}

void display2D(vvi &dp)
{
    for (vi &ar : dp)
    {
        for (int &ele : ar)
            cout << ele << " ";
        cout << endl;
    }
}

int64_t fibonacci(int n)
{
    int64_t a = 0, b = 1, c = 0;
    for (int i = 2; i <= n; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}

// gfg count of ways to divide n people into k sets;
int count_of_ways(int n, int k)
{
    if (n < k)
        return 0;
    if (n == k || k == 1)
        return 1;

    vector<vector<int>> dp(2, vector<int>(k + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        int idx = (1 & i); // to simulate 2D effect in 1d this step just alter the index b\w 1 and 0;
        for (int j = 1; j <= i && j <= k; j++)
        {
            if (j == 1 || i == j)
            {
                dp[idx][j] = 1;
                continue;
            }
            if (idx == 1)
                dp[idx][j] = dp[idx - 1][j - 1] + dp[idx - 1][j] * j;
            else
                dp[idx][j] = dp[1 - idx][j - 1] + dp[1 - idx][j] * j;
        }
    }

    display2D(dp);
    return (n & 1) ? dp[1][k] : dp[0][k];
}

void solve()
{
    // cout << fibonacci(105) << "\n";
    cout << count_of_ways(5, 2) << endl;
}

int main()
{
    solve();
    cout << '\n';
    return 0;
}