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

// substring and subsequence using optimized dp solutions;
void isPalindromeSubstring(string str)
{
    int n = str.size(); // dp[i][j] will store that the string from i to j is palindrome or not;
    vvi dp(n, vi(n, 0));
    for (int gap = 0; gap < n; gap++)
    {
        for (int i = 0, j = gap; j < n; j++, ++i) // gap type loop used;
        {
            if (gap == 0)
            {
                dp[i][j] = true; // string of size 1;
                continue;
            }
            if (gap == 1 && str[i] == str[j])
                dp[i][j] = true;
            else if (str[i] == str[j] && dp[i + 1][j - 1])
                dp[i][j] = true;
        }
    }

    display2D(dp);
}

int longestPalindromeSubstring(string str) //Time: O(N^2), Space: O(n^2);
{
    int n = str.size(); // dp[i][j] will store the longrest palindrome string from i to j if its palindrome;
    vvi dp(n, vi(n, 0));
    int omax = 0;
    for (int gap = 0; gap < n; gap++)
    {
        for (int i = 0, j = gap; j < n; j++, ++i) // gap type loop used;
        {
            if (gap == 0)
            {
                dp[i][j] = 1; // string of size 1;
                continue;
            }
            if (gap == 1 && str[i] == str[j])
                dp[i][j] = 2; //string of size 2;
            else if (str[i] == str[j] && dp[i + 1][j - 1] != 0)
                dp[i][j] = dp[i + 1][j - 1] + 2;
            omax = max(omax, dp[i][j]);
        }
    }

    display2D(dp);
    return omax;
}

// Space Optimized soltuion for longes Plaindrome substirng;
int longestPalindormeSubstring_SpaceOptimized(string str) //Time: O(N^2), Space: O(1);
{
    // Main Idea starts:
    // The idea is to check for every index as the startig index as mid point then checking for every even & odd
    //length string form mid point by incrementing the low and high indexes and updating maxValue for overallMax;
    int n = str.size();
    int omax = 0;
    for (int i = 1; i < n; i++) // running loop for every index as mid;
    {
        int low = i - 1, high = i + 1;
        while (low >= 0 && high <= n && str[low] == str[high]) //for odd longest length of string;
        {
            omax = max(omax, high - low + 1);
            low--;
            high++;
        }

        low = i, high = i + 1;
        while (low >= 0 && high <= n && str[low] == str[high]) //for even longest length of string;
        {
            omax = max(omax, high - low + 1);
            low--;
            high++;
        }
    }

    return omax;
}

int longestPalindromeSubseq(string str) //Time : O(N^2) Space : O(N^2);
{
    int n = str.size();
    vvi dp(n, vi(n, 0)); // dp[i][j] will store the longest palindrome from index i to j;
    for (int gap = 0; gap < n; gap++)
    {
        for (int i = 0, j = gap; j < n; i++, ++j)
        {
            if (gap == 0)
            {
                dp[i][j] = 1;
                continue;
            }
            if (str[i] == str[j])
                if (gap == 1)
                    dp[i][j] = 2;
                else
                    dp[i][j] = dp[i + 1][j - 1] + 2;
            else
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
        }
    }

    return dp[0][n-1];
}

void solve()
{
    // cout << fibonacci(105) << "\n";
    // cout << count_of_ways(5, 2) << endl;
    // isPalindromeSubstring("abaccab");
    // cout << longestPalindromeSubstring("abaccabe");
    // cout << longestPalindormeSubstring_SpaceOptimized("abaccabe");
    cout << longestPalindromeSubseq("abackecabe");
}

int main()
{
    solve();
    cout << '\n';
    return 0;
}