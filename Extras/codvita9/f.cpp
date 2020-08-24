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

bool isPalin(string &str)
{
    int n = str.size();
    int  i = 0, j = n - 1;
    while (i < j)
    {
        if (str[i] == str[j])
        {
            i++;
            j++;
        }
        else
            return false;
    }
    cout << str << endl;
    return true;
}

bool getPalin(string str, int count, string ans)
{
    if (0 == str.size() || count == 3)
    {
        if (count == 3 && 0 == str.size())
        {
            for (int i = 0; i < ans.size(); i++)
            {
                if (ans[i] == '*')
                    cout << endl;
                else
                    cout << ans[i];
            }
            return true;
        }

        return false;
    }
    cout<<str;
    bool res = false;
    for (int i = 1; i <= str.size(); i++)
    {
        string tmp = str.substr(0, i);
        cout<<tmp<<" ";
        if (isPalin(tmp))
            res = res || getPalin(str.substr(i), count + 1, ans + tmp + '*');
        
    }
    return res;
}

int main()
{
    string str;
    cin >> str;
    getPalin(str, 0, "");
    return 0;
}