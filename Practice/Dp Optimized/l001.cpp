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
int coinChangePermutation(vi &coins, int n, int target)
{
    vi dp(target + 1, 0); //dp[i] will store the no of ways to get the target i using all the coins if possible;
    dp[0] = 1;
    for (int tar = 1; tar <= target; tar++)
    {
        for (int ele : coins)
            if (tar - ele >= 0)
                dp[tar] += dp[tar - ele];
    }

    return dp[target];
}

// the order of the coins doesn't matter no need to sort;
int coinChangeCombination(vi &coins, int n, int target)
{
    vi dp(target + 1, 0);
    dp[0] = 1;            // dp[i] will store the count of no of ways to acheive the i target using each coin;
    for (int ele : coins) // this is effect loop in this each coin will produce its effect on each i target;
        for (int i = ele; i <= target; i++)
            dp[i] += dp[i - ele];
}

//Target Sum dp solution which uses coin change combination of subsequenece type recursion structur;
int TargetSum(vi &coins, int n, int target) // Time: O(N^2), Space: O(N^2);
{
    vvi dp(n + 1, vi(target + 1, 0)); // dp[idx][tar] will store the no of ways to get tar using idx coins and by not using idx coins;
    dp[0][0] = 1;                     // no of ways to get 0 target with 0 & more coins is 1 i.e don't use any coin;
    for (int idx = 1; idx <= n; idx++)
    {
        for (int tar = 0; tar <= target; tar++)
        {
            if (tar == 0)
            {
                dp[idx][tar] = 1;
                continue;
            }

            if (tar - coins[idx - 1] >= 0) // condition for using that coin;
                dp[idx][tar] += dp[idx - 1][tar - coins[idx - 1]];
            dp[idx][tar] += dp[idx - 1][tar]; // condition for not using that coin;
        }
    }

    return dp[n][target];
}

int TargetSum_SpaceOptimized(vi &coins, int n, int target) // Time: O(N^2), Space: O(N);
{
    vvi dp(2, vi(target + 1, 0));
    int i;
    dp[0][0] = 1;
    for (int idx = 1; idx <= n; idx++)
    {
        i = idx & 1; // using the idx method;
        for (int tar = 0; tar <= target; tar++)
        {
            if (tar == 0)
            {
                dp[i][tar] = 1;
                continue;
            }
            dp[i][tar] = 0;
            if (tar - coins[idx - 1] >= 0)
                dp[i][tar] += dp[1 - i][tar - coins[idx - 1]];
            dp[i][tar] += dp[1 - i][tar];
        }
        display2D(dp);
    }

    return dp[i][target];
}

// 0/1 Knapsack problem using the same targetsum stratergy i.e either we pick the item or we just leave the item;
int kanpsack01(vi &wet, vi &val, int n, int weight) //Time: O(N^2), Space: O(N^2);
{
    vvi dp(n + 1, vi(weight + 1, 0)); //dp[i][w] will store the max profit by using the ith ele or by not;
    dp[0][0] = 0;                     // total profit by picking no element is 0;
    for (int i = 1; i <= n; i++)
    {
        for (int w = 0; w <= weight; w++)
        {
            if (w - wet[i - 1] >= 0) // pick the element; and ab jo mere kanpsack ki capacity baach gai h usse m baki i-1 elements bahrkar kitna profit kama skta hu;
                dp[i][w] = max(dp[i][w], dp[i - 1][w - wet[i - 1]] + val[i - 1]);
            dp[i][w] = max(dp[i][w], dp[i - 1][w]); // no pick then max profit by using i-1 elements to fill the kanpsack;
        }
    }

    return dp[n][weight];
}

int kanpsack01_SpaceOptimized(vi &wet, vi &val, int n, int weight) //Time: O(N^2), Space: O(N);
{
    vvi dp(2, vi(weight + 1, 0));
    dp[0][0] = 0;
    int idx;
    for (int i = 1; i <= n; i++)
    {
        idx = 1 & i;
        for (int w = 0; w <= weight; w++)
        {
            if (w - wet[i - 1] >= 0)
                dp[idx][w] = dp[1 - idx][w - wet[i - 1]];
            dp[idx][w] = max(dp[idx][w], dp[1 - idx][w]);
        }
    }

    return dp[idx][weight];
}

int knapsack01_SpaceOptimized_01(vi &wet, vi &val, int n, int weight) //Time: O(N^2), Space: O(N);
{
    vi dp(weight + 1, 0);
    for (int i = 0; i < n; i++)
    {
        for (int w = weight; w >= wet[i]; w--)           //dp[w] will store the max profit to fill the w weight kanpsack;
            dp[w] = max(dp[w], val[i] + dp[w - wet[i]]); //dp[w] =  max profit if i don't include the element;
    }                                                    // val[i] + dp[w - wet[i]] = max profit if i include the ith element

    return dp[weight];
}

// MatrixChain Multiplication
int MCM(vi &arr, int si, int ei, vvi &dp)
{
    if (si + 1 == ei)
    {
        dp[si][ei] = 0;
        return;
    }

    if (dp[si][ei] != -1)
        return dp[si][ei];

    int ans = 1e9;
    for (int cut = si + 1; cut < ei; cut++)
    {
        int left = MCM(arr, si, cut, dp);  // left wala muje apna multiplication cost dega and multiply ho kr aeyga;
        int right = MCM(arr, cut, ei, dp); // right wale muje apne multiplication cost dega & multiply ho kr aeyga;

        int myans = left + arr[si] * arr[cut] * arr[ei] + right; // then m left & right ko multiply karne ka cost nikalunga;
        if (myans < ans)
            ans = myans;
    }

    dp[si][ei] = ans;
}

int MCM_DP(vi &arr, int n)
{
    vvi dp(n, vi(n, 0)); // dp[si][ei] will store the min multiplication cost required to multiply matrix from i to j;
    for (int gap = 0; gap < n; gap++)
    {
        for (int si = 0, ei = gap; ei <= n; si++, ei++)
        {
            if (si + 1 == ei)
            {
                dp[si][ei] = 0;
                continue;
            }
            int ans = 1e9;
            for (int cut = si + 1; cut < ei; cut++) // putting the cut b/w the si and ei;
            {
                int left = dp[si][cut];
                int right = dp[cut][ei];

                int myans = left + arr[si] * arr[cut] * arr[ei] + right;
                if (myans < ans)
                    myans = ans;
            }
            dp[si][ei] = ans;
        }
    }
    return dp[0][n];
}

//Cost of searching in optimal binary search tree;
int CostOfSearching(vi &freq, int si, int ei)
{
    int sum = 0;
    for (int i = si; i <= ei; i++)
        sum += freq[i];
    return sum;
}

int OBST(vi &freq, int si, int ei, vvi &dp) //Time: O(N^4), Space:O(N^2);
{
    if (dp[si][ei] != 0)
        return dp[si][ei];
    int ans = 1e8;
    for (int cut = si; cut <= ei; cut++) // me ith index ko root node bana kr left aur right se bolunga tum apna dekh lo;
    {
        int leftTreeCost = si == cut ? 0 : OBST(freq, si, cut - 1, dp);
        int rightTreeCost = ei == cut ? 0 : OBST(freq, cut + 1, ei, dp);

        int myans = leftTreeCost + CostOfSearching(freq, si, ei) + rightTreeCost;
        if (ans > myans)
            ans = myans;
    }

    return dp[si][ei] = ans;
}

int OBST_DP(vi &freq, int n)
{
    vi prefiSum(n + 1, 0); // it will store the sum of prefixe till that index;
    for (int i = 1; i <= n; i++)
        prefiSum[i] = prefiSum[i - 1] + freq[i - 1];
    vvi dp(n, vi(n, 0));
    for (int gap = 0; gap < n; gap++) // dp[si][ei] = min cost of make OBST from si to ei;
    {
        for (int si = 0, ei = gap; ei < n; si++, ei++)
        {
            int ans = 1e9;
            for (int cut = si; cut <= ei; cut++)
            {
                int leftTreeCost = si == cut ? 0 : dp[si][cut - 1];
                int rightTreeCost = ei == cut ? 0 : dp[cut + 1][ei];
                int myans = leftTreeCost + prefiSum[ei + 1] - prefiSum[si] + rightTreeCost;
                if (ans > myans)
                    ans = myans;
            }
            dp[si][ei] = ans;
        }
    }

    return dp[0][n - 1];
}

// Baloon Brust dp

int brustBaloon(vi &arr, int si, int ei, vvi &dp)
{
    if (dp[si][ei] != 0)
        return dp[si][ei];
    int l = si == 0 ? 1 : arr[si - 1];
    int r = ei == arr.size() - 1 ? 1 : arr[ei + 1];
    int ans = 0;
    for (int cut = si; cut <= ei; cut++)
    {
        int leftCost = cut == si ? 0 : brustBaloon(arr, si, cut - 1, dp);
        int rightCost = cut == ei ? 0 : brustBaloon(arr, cut + 1, ei, dp);

        int mycost = leftCost + l * arr[cut] * r + rightCost;
        if (mycost > ans)
            ans = mycost;
    }

    return dp[si][ei] = ans;
}

int brustBaloonDP(vi &arr)
{
    int n = arr.size();
    vvi dp(n, vi(n, 0));
    for (int gap = 0; gap < n; gap++)
    {
        for (int si = 0, ei = gap; ei < n; si++, ei++)
        {
            int ans = 0;
            int l = si == 0 ? 1 : arr[si - 1];
            int l = ei == n - 1 ? 1 : arr[ei + 1];
            for (int cut = si; cut <= ei; cut++)
            {
                int leftCost = si == cut ? 0 : dp[si][cut - 1];
                int rightCost = ei == cut ? 0 : dp[cut + 1][ei];

                int mycost = leftCost + l * arr[cut] * r + rightCost;
                if (ans < mycost)
                    ans = mycost;
            }
        }
    }
    return dp[0][n - 1];
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
    // cout << longestCommonSubseq_SpaceOptimized_01("abcba", "abcbcba");
    vi coins = {2, 3, 5, 7};
    cout << TargetSum_SpaceOptimized(coins, 4, 10);
}

int main()
{
    solve();
    cout << '\n';
    return 0;
}