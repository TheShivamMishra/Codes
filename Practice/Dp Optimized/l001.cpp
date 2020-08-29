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
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i && j<=k; j++)
        {
            if (j == 1 || i == j)
            {
                dp[i][j] = 1;
                continue;
            }

            dp[i][j] = dp[i-1][j-1] + dp[i-1][j]*j;
        }
    }

    display2D(dp);
    return dp[n][k];
}

void solve()
{
    // cout << fibonacci(105) << "\n";
    cout<<count_of_ways(5,2)<<endl;
}

int main()
{
    solve();
    cout << '\n';
    return 0;
}