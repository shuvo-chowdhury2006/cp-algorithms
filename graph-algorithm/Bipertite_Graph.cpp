#include<bits/stdc++.h>
using namespace std;
vector<int>adj_list[200005];
void shiro_oni()
{
    int n,e; cin>>n>>e;
    while(e--){
        int a,b; cin>>a>>b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    vector<int>team(n+1,0);
    queue<int>q;
    for(int i = 1;i<=n;i++){
        if(team[i]!=0) continue;
        q.push(i);
        team[i] = 1;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(auto v : adj_list[u]){
                if(team[v] == 0){
                    team[v] = (team[u] == 1? 2 : 1);
                    q.push(v);
                }else if(team[v] == team[u]) {
                    cout<<"IMPOSSIBLE"<<endl;
                    return;
                }
            }
        }
    }
    for(int i = 1;i<=n;i++) cout<<team[i]<<" ";
    cout<<endl;
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