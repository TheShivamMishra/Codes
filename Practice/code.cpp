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

int main()
{
    int t, i = 1;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        queue<int> que;
        vector<int> arr(n, 0);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            que.push(i + 1);
        }

        vector<int> ans;
        while (que.size() != 0)
        {
            // cout<<que.front()<<" "<<arr[que.front()-1]<<endl;
            if (arr[que.front() - 1] > x)
            {
                arr[que.front() - 1] = arr[que.front() - 1] - x;
                int idx = que.front();
                que.pop();
                que.push(idx);
            }
            else if(arr[que.front()-1]!=0)
            {
                // cout<<que.front()<<endl;
                ans.push_back(que.front());
                que.pop();
            }
        }

        cout << "Case #" << i << ": ";
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << " ";
        cout<<'\n';    
        i++;
    }
}