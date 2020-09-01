#include <cmath>
#include <cstdio>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <algorithm>
#define vi vector<int>
#define vb vector<bool>
#define vvi vector<vector<int>>
using namespace std;

class Solution
{
public:
    Solution()
    {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    }

    void solve()
    {
        cout<<shortestCommonSupersequence("cab","abac");
    }

    string shortestCommonSupersequence(string str1, string str2)
    {
        int n = str1.size();
        int m = str2.size();
        if (n == 0 || m == 0)
            return n == 0 ? str2 : str1;
        vector<vector<string>> dp(n + 1, vector<string>(m + 1, ""));
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= m; j++)
            {
                if (i == 0 || j == 0)
                    continue;
                if (str1[i - 1] == str2[j - 1])
                    dp[i][j] = dp[i-1][j-1] + str1[i - 1];
                else
                    dp[i][j] = dp[i - 1][j].size() > dp[i][j - 1].size() ? dp[i - 1][j] : dp[i][j - 1];
            }
            // cout << endl;
        }

      for(int i=0;i<=n;i++)
      {
          for(int j=0;j<=m;j++)
          {
              cout<<dp[i][j]<<" ";
          }
          cout<<endl;
      }

        string res = "";
        int i = 0, j = 0;
        for (char ch : dp[n][m])
        {
            // cout << ch << endl;
            while (str1[i] != ch)
            {
                res += str1[i];
                i++;
            }

            while (str2[j] != ch)
            {
                res += str2[j];
                j++;
            }
            res += ch;
            i++;
            j++;
        }
        res += str1.substr(i);
        res += str2.substr(j);
        return res;
    }
};

int main()
{

    Solution obj;
    obj.solve();
    cout << endl;
}