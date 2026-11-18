#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,x; cin>>n>>x;
    vector<int>cost(n),pages(n);
    for(auto &x : cost) cin>>x;
    for(auto &x : pages) cin>>x; 

    vector<int>dp(x+1,0); 
    
    for(int i = 0;i<n;i++){
        for(int c = x ; c >= cost[i] ; c--){
            dp[c] = max(dp[c],dp[c-cost[i]]+pages[i]);
        }
    }
    cout<<dp[x]<<endl;
    return 0;
}
//https://cses.fi/problemset/task/1158
