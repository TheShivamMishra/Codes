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

int gcd(int a,int b)
{
    if(a==0) return b;
    return gcd(b%a,a);
}

void solve()
{
    int n, mi = 0;
    cin >> n;
    int arr[n];
    loop(n)
    {
        cin >> arr[i];
        mi = arr[i] > arr[mi] ? i : mi;
    }
    vi b(n, 0);
    b[0] = arr[mi];
    arr[mi] = 0;
    int tillgcd = b[0];
    for (int i = 1; i < n; i++)
    {
        int cgcd = 0, ci = i;
        for (int j = 0; j < n; j++)
        {
            if (arr[j] && cgcd < gcd(tillgcd, arr[j]))
            {
                cgcd = gcd(tillgcd, arr[j]);
                ci = j;
            }
        }
        b[i] = arr[ci];
        tillgcd = cgcd;
        arr[ci] = 0;
    }

    loop(n) cout<<b[i]<<" ";
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
        cout << '\n';
    }
    return 0;
}