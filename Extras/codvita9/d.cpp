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

bool found(string str, unordered_map<string, vector<int>> &map)
{
    vi freq(26, 0);
    for (int i = 0; i < (int)str.size(); i++)
        freq[str[i] - 'a']++;

    for (auto e : map)
    {
        vi temp = e.second;
        bool ok = true;
        for (int i = 0; i < 26; i++)
        {
            if (freq[i] != temp[i])
            {
                ok = false;
                break;
            }
        }

        if (ok)
            return true;
    }

    return false;
}

bool match(string word, unordered_map<string, vector<int>> &map)
{
    if (word.size() == 0)
        return true;

    bool res = false;
    for (int i = 1; i <= (int)word.size(); i++)
    {
        string str = word.substr(0, i);
        if (found(str, map))
            res = res || match(word.substr(i), map);
    }

    return res;
}

void solve()
{
    string word, str;
    cin >> word;
    int n;
    cin >> n;
    unordered_map<string, vector<int>> map;
    for (int i = 0; i < n; i++)
    {
        vi freq(26, 0);
        cin >> str;
        for (int i = 0; i <(int) str.size(); i++)
            freq[str[i] - 'a']++;
        map[str] = freq;
    }
    int m = word.size();
    if (match(word, map))
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    solve();
    return 0;
}