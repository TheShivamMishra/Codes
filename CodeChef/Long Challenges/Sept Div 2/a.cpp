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

const int N = 1e5+1;
int arr[N];
int solve()
{
    memset(arr,0,sizeof(arr));
    int n;
    cin>>n;
    int omax = 0;
    for(int i =0;i<n;i++)
    {
        int a;
        cin>>a;
        omax = a>omax?a:omax;
        arr[a] = 1;
    }
    int cut =0,prev = omax;
    for(int i=omax-1;i>=0;i--)
    {
        if(arr[i])
        {
            cut++;
           
        }
    }
    return cut+1;
}

int main()
{
    int t;
    cin>>t;
    while (t--) {
        cout<<solve()<<'\n';
    }
    return 0;
}