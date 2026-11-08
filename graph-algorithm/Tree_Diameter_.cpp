#include<bits/stdc++.h>
using namespace std;
const int MAXN = 200005;
vector<int>adj_list[MAXN];
int farthest(int src,vector<int>&dis){
    dis.assign(MAXN,INT_MAX);
    vector<int>vis(MAXN,false);
    dis[src] = 0 , vis[src] = true;
    queue<int>q;
    q.push(src);
    int mx_dis = -1, mx_dis_val = -1;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        if(dis[u]>mx_dis){
            mx_dis = dis[u];
            mx_dis_val = u;
        }
        for(auto v : adj_list[u]){
            if(vis[v]) continue;
            vis[v] = true;
            dis[v] = min(dis[v],dis[u]+1);
            q.push(v);
        }
    }
    return mx_dis_val;
}
int main(){
    int n; cin>>n;
    for(int i = 1;i<n;i++){
        int u,v; cin>>u>>v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    vector<int>d(MAXN),D1(MAXN),D2(MAXN);
    int a = farthest(1,d);
    int b = farthest(a,D1);
    farthest(b,D2);
    for(int i = 1;i<=n;i++){
        cout<<max(D1[i],D2[i])<<(i == n ? "\n" : " ");
    }
    return 0;
}