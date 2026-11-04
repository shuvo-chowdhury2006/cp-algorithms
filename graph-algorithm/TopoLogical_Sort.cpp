#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(a) (a).begin(),(a).end()
const int MAXN = 100005;
vector<int> adj_list[MAXN];
int vis[MAXN];
vector<int> ans;
bool invalid = false;

void dfs(int u){
    vis[u] = 1;
    for(auto v : adj_list[u]){
        if(vis[v] == 1){ 
            invalid = true;
            return;
        }
        if(vis[v] == 0){
            dfs(v);
            if(invalid) return;
        }
    }
    vis[u] = 2;
    ans.pb(u);
}

void shiro_oni()
{
    int n, m; cin>>n>>m;
    for(int i = 1; i <= n; i++){
        adj_list[i].clear();
        vis[i] = 0;
    }
    ans.clear();
    invalid = false;
    while(m--){
        int u, v; 
        cin >> u >> v;
        adj_list[u].pb(v);
    }
    for(int i = 1; i <= n; i++){
        if(vis[i] == 0){
            dfs(i);
            if(invalid) break;
        }
    }
    if(invalid){
        cout << "IMPOSSIBLE\n";
        return;
    }
    reverse(all(ans));
    for(int i = 0; i < n; i++) {
        cout << ans[i] << (i == n - 1 ? "" : " ");
    }
    cout << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--)
    {
       shiro_oni();
    }
    return 0;
}