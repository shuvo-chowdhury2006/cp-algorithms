#include<bits/stdc++.h>
using namespace std;
vector<int> adj_list[100005];
vector<int>vis(100005);
void dfs(int src){
    vis[src] = true;
    for(auto child : adj_list[src]){
        if(!vis[child]){
            dfs(child);
        }
    }
}
void shiro_oni()
{
    int n,e; cin>>n>>e;
    while(e--){
        int a,b; cin>>a>>b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    vector<int>k;
    for(int i = 1;i<=n;i++){
        if(!vis[i]){
            k.push_back(i);
            dfs(i);
        }
    }
    cout<<k.size()-1<<endl;
    for(int i = 0;i<k.size()-1;i++){
        cout<<k[i]<<" "<<k[i+1]<<endl;
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
    // https://cses.fi/problemset/task/1666
}