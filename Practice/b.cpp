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

int sleepNode(vvi &tree, int start, int end, int p)
{
    cout<<start<<endl;
    if (p == 0 || start == end)
        return start;
    int ans = 0;
    for (int e : tree[start])
    {
        ans = sleepNode(tree, e, end, p - 1);
        if (ans != 0)
            return ans;
    }
    return ans;
}

void solve()
{
    int n;
    cin >> n;
    vvi tree(n+1);
    // int d = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
    }

    int q;
    cin >> q;
    while (q--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        int node = sleepNode(tree, a, b, c);
        cout << node << "\n";
    }
    cout << "\n";
}

int main()
{
    solve();
    return 0;
}