#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>oset;
using i128 = __int128_t;
#define pb push_back
#define lcm(a,b) ((a)/__gcd(a,b)*(b))
#define all(a) (a).begin(),(a).end()
#define popcnt(x) __builtin_popcountll(x)
#define uniq(a) (a).erase(unique((a).begin(), (a).end()), (a).end())
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define endl '\n'
const int MAXN = 100005;
vector<int>adj_list[MAXN];
vector<pair<int,int>>ans;
bool bridge_found;
vector<int> vis(MAXN,0);
int dp[MAXN];
void dfs(int u,int p){
    vis[u] = 1;
    for(auto v : adj_list[u]){
        if(v == p) continue;
        if(vis[v] == 1){
            ans.pb({u,v});
            dp[u]++;
            dp[v]--;
        }else if(vis[v] == 0){
            dfs(v,u);
            ans.pb({u,v});
            dp[u]+=dp[v];
            if(dp[v] == 0){
                bridge_found = true;
                return;
            }
        }
    }
    vis[u] = 2;
}
void shiro_oni()
{
    int n,e; cin>>n>>e;
    while(e--){
        int u,v; cin>>u>>v;
        adj_list[u].pb(v);
        adj_list[v].pb(u);
    }
    dfs(1,-1);
    if(bridge_found) cout<<0<<endl;
    else{
        for(auto const& [x,y] : ans) cout<<x<<" "<<y<<endl;
    }
}
int32_t main()
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