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
    int n = str.size(); // dp[i][j] will store the longrest palindrome substring from i to j if its palindrome;
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
    display2D(dp);
    return dp[0][n - 1];
}

/*
int longestPalindromeSubseq_SpaceOptimized(string str) //Time : o(N^2) Space : O(N);
{
    int n = str.size();
    vi dp(n, 0);     // dp[i] will store the longestpalindrome upto that index;
    int lastMax = 0; // lastMax is used to store the previous maximum;
    for (int gap = n - 1; gap >= 0; gap--)
    {
        for (int i = gap, j = n - 1; i >= 0; i--, j--)
        {
            if (gap == n - 1)
            {
                dp[i] = 1;
                lastMax = 1;
                continue;
            }

            if (str[i] == str[j])
            {
                if (gap == n - 2)
                    dp[i] = 2;
                else
                    dp[i] = lastMax + 2;
                lastMax = dp[i];
            }
            else
                dp[i] = max(dp[i], dp[i - 1]);
        }
        display(dp);
    }
    // display(dp);
    return dp[0];
}
*/

int longestCommonSubsequence(string str1, string str2) //Time : O(N^2), Space O(N^2)
{
    int n = str1.size();
    int m = str2.size();

    vvi dp(n + 1, vi(m + 1, 0)); // dp[i][j] will store the longest common subsequence i.e dp[i][j] contains length of LCS of X[0..i - 1] and Y[0..j - 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)
                continue;

            if (str1[i - 1] == str2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        }
    }
    display2D(dp);
    return dp[n][m];
}

int longestCommonSubseq_SpaceOptimized(string str1, string str2) //Time: O(N^2), Space O(2N);
{
    int n = str1.size();
    int m = str2.size();
    vvi dp(2, vi(m + 1, 0)); //its dp[i][j] will goining to store the longest subsequnce i.e dp[i][j] contains length of LCS of X[0..i - 1] and Y[0..j - 1];
    int idx;
    for (int i = 0; i <= n; i++)
    {
        idx = (1 & i); // using to simulate 2D effedt in 1-D using idx;
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)
                continue;
            if (str1[i - 1] == str2[j - 1])
                dp[idx][j] = dp[1 - idx][j - 1] + 1;
            else
                dp[idx][j] = max(dp[1 - idx][j], dp[idx][j - 1]);
        }
    }
    // display2D(dp);
    return dp[idx][m];
}

int longestCommonSubseq_SpaceOptimized_01(string str1, string str2)
{
    int n = str1.size();
    int m = str2.size();
    vi dp(m + 1, 0);
    int prev = 0;

    for (int i = 0; i <= n; i++)
    {
        prev = 0;
        for (int j = 0; j <= m; j++)
        {
            int tmp = dp[j];
            if (i == 0 || j == 0)
                continue;
            if (str1[i - 1] == str2[j - 1])
            {
                // int temp = dp[j];
                dp[j] = prev + 1;
                // prev = temp;
            }
            else
                dp[j] = max(dp[j], dp[j - 1]);
            prev = tmp;
        }
        display(dp);
    }

    return dp[m];
}

//coin change using dp
int coinChangePermutation(vi &coins, int n)
{
    vi dp(n + 1, 0);
}
void solve()
{
    // cout << fibonacci(105) << "\n";
    // cout << count_of_ways(5, 2) << endl;
    // isPalindromeSubstring("abaccab");
    // cout << longestPalindromeSubstring("abaccabe");
    // cout << longestPalindormeSubstring_SpaceOptimized("abaccabe");
    // cout << longestPalindromeSubseq("abackecabe");
    // cout << longestPalindromeSubseq_SpaceOptimized("abackecabe");
    // cout << longestCommonSubsequence("abefk", "egabe");
    // cout << longestCommonSubseq_SpaceOptimized("abefk", "egabe");
    cout << longestCommonSubseq_SpaceOptimized_01("abcba", "abcbcba");
}

int main()
{
    solve();
    cout << '\n';
    return 0;
}