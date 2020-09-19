#include <iostream>
#include <vector>
#include <queue>
#define lli long long int
using namespace std;
lli min_cost = 1e12;


// void solve(int src,int evtx,lli ccost,lli cost,vector<vector<pair<int,int>>>& graph,vector<int>& vis)
// {
//     cost += ccost;
//     // cout<<src<<" "<<ccost<<" "<<cost<<"\n";
//     if(src == evtx)
//     {
//         // cout<<min_cost<<endl;
//         min_cost = min_cost>cost?cost:min_cost;
//         return;
//     }
//     lli mycost =1e15;
//     vis[src] = true;
//     for(auto e : graph[src])
//     {
//        if(!vis[e.first])
//        {
//            mycost = e.second - cost;
//            lli costToReachE = mycost<0?0:mycost;
//            solve(e.first,evtx,costToReachE,cost,graph,vis);
//        }
//     }
//     vis[src] = false;
// }

struct comp
{
public:
    bool operator()(vector<lli> &a, vector<lli> &b)
    {
        return a[1] > b[1];
    }
};

void bfs(int n, vector<vector<pair<int, int>>> &graph, vector<int> &vis)
{
    priority_queue<vector<lli>, vector<vector<lli>>, comp> que;
    que.push({1, 0, 0});
    lli ccost = 0;
    while (que.size() != 0)
    {
        int size = que.size();
        while (size--)
        {
            vector<lli> rvtx = que.top();
            que.pop();
            cout<<rvtx[0]<<" "<<rvtx[1]<<" "<<rvtx[2]<<"\n";
            if (vis[rvtx[0]])
                continue;
            if (rvtx[0] == n)
            {
                min_cost = rvtx[2] < min_cost ? rvtx[2] : min_cost;
                continue;
            }

            vis[rvtx[0]] = true;
            for (auto e : graph[rvtx[0]])
            {
                if (!vis[e.first])
                {
                    lli mycost = e.second - rvtx[2];
                    if (mycost < 0)
                        mycost = 0;
                    que.push({e.first, mycost, mycost + rvtx[2]});
                }
            }
        }
    }
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    // cost =0;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, e, u, v, w;
    cin >> n >> e;
    vector<vector<pair<int, int>>> graph(n + 1);
    for (int i = 0; i < e; i++)
    {
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
    vector<int> vis(n + 1, false);
    // solve(1,n,0,0,graph,vis);
    bfs(n, graph, vis);
    if (min_cost != 1e12)
        cout << min_cost << endl;
    else
        cout << "NO PATH EXISTS" << endl;
    return 0;
}
