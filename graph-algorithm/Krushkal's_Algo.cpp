#include<bits/stdc++.h>
using namespace std;
class DSU{
    private : 
        vector<int>parent;
    public :
        DSU(int n){
            parent.resize(n+1,-1);
        }
        int find(int node){
             if(parent[node] == -1) return node;
             return parent[node] = find(parent[node]);
        }
        void unite(int node1,int node2){
            int leader1 = find(node1);
            int leader2 = find(node2);
            parent[leader2] = leader1; 
        }
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m; cin>>n>>m;
    vector<array<int,3>>edge;
    while(m--){
        int u,v,w; cin>>u>>v>>w;
        edge.push_back({w,u,v});
    }
    sort(edge.begin(),edge.end());
    DSU dsu(n);
    int cost = 0;
    for(auto ed : edge){
        int w = ed[0] , u = ed[1] , v = ed[2];
        if(dsu.find(u) == dsu.find(v)) continue;
        dsu.unite(u,v);
        cout<<u<<" "<<v<<endl;
        cost += w;
    }
    cout<<cost<<endl;
    return 0;
}