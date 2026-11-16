#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(a) (a).begin(),(a).end()
const int MAXN = 100005;
vector<int>adj_list[MAXN];
int vis[MAXN];
int cycle_start,cycle_end;
vector<int>parent(MAXN,-1);
bool dfs(int u,int p){
    vis[u] = 1;
    for(auto v : adj_list[u]){
        if(v == p) continue;
        if(vis[v] == 1){
            cycle_start = v;
            cycle_end = u;
            return true;
        }else if(vis[v] == 0){
            parent[v] = u;
            if(dfs(v,u)) return true;
        }
    }
    vis[u] = 2;
    return false;
}
void shiro_oni()
{
    int n,m; cin>>n>>m;
    while(m--){
        int u,v; cin>>u>>v;
        adj_list[u].pb(v);
        adj_list[v].pb(u);
    }
    for(int i = 1;i<n;i++){
        if(!vis[i]){
            if(dfs(i,-1)){
                vector<int>cycle;
                for(int v = cycle_end ; v != cycle_start; v = parent[v]){
                    cycle.pb(v);
                }
                cycle.pb(cycle_start);
                reverse(all(cycle));
                cycle.pb(cycle_start);
                cout<<cycle.size()<<endl;
                for(auto x : cycle) cout<<x<<" ";
                cout<<endl;
                return;
            }
        }
    }
    cout<<"IMPOSSIBLE"<<endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    while(t--)
    {
       shiro_oni();
    }
    return 0;
}