#include "bits/stdc++.h"
#define vi vector<int>
#define vb vector<bool>
#define lli long long int
#define vvi vector<vector<int>>
#define loop(n) for (int i = 0; i < n; i++)
using namespace std;

// auto SpeedUp = []() {
//     #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
//     #endif
//     std::ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cout.tie(nullptr);
//     return 0;
// }();

int ask(int x, int y)
{
    printf("? %d %d\n",x,y);
    // cout << "? " << x + 1 << ' ' << y + 1 << "\n";
    int ans;
    scanf("%d",&ans);
    return ans;
}

void solve()
{
    int n;
    scanf("%d",&n);
    vector<int> arr(n, 0);
    int li = 0;
    for (int i = 1; i < n; i++)
    {
        int a = ask(li, i);
        int b = ask(i, li);
        if (a > b)
        {
            arr[li] = a;
            li = i;
        }
        else
        {
            arr[i] = b;
        }
    }
    arr[li] = n;
    printf("! ");
    loop(n) printf("%d ",arr[i]);
}

int main()
{
    // solve();
    int n = 5;
    vi arr(n,0);
    printf("! ");
    loop(n) printf("%d \n",arr[i]);
    printf("\n");
    return 0;
}