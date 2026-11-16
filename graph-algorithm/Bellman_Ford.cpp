#include<bits/stdc++.h>
using namespace std;
#define int long long
struct Edge{
    int u,v,w;
};
int n,m; 
vector<Edge>edges;
vector<int>dist;
void bellman_ford(int src){
    dist.assign(n+1,0);
    vector<int>parent(n+1,-1);
    for(int i = 1;i<=n-1;i++){
        bool any_change = false;
        for(auto edge : edges){
            int u = edge.u;
            int v = edge.v;
            int w = edge.w;

            if(dist[u]+w<dist[v]){
                dist[v] = dist[u] + w;
                any_change = true;
                parent[v] = u;
            }
        }
        if(!any_change) break;
    }
    int x = -1;
    for(auto edge : edges){
        int u = edge.u;
        int v = edge.v;
        int w = edge.w;

        if(dist[u]+w<dist[v]){
            x = v;
            parent[x] = u;
            break;
        }
    }
    if(x == -1){
        cout<<"NO"<<endl;
        return;
    }
    for(int i = 1;i<=n;i++) x = parent[x];
    vector<int>cycle;
    for(int v = x; ;v = parent[v]){
        cycle.push_back(v);
        if(v == x && cycle.size()>1) break;
    }
    cout<<"YES"<<endl;
    reverse(begin(cycle),end(cycle));
    for(auto it : cycle) cout<<it<<" ";
    cout<<endl;
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    while(m--){
        int u,v,w; cin>>u>>v>>w;
        edges.push_back({u,v,w});
    }
    bellman_ford(1);
    return 0;
}
