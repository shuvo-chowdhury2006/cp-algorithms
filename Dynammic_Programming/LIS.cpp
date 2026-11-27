#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(a) (a).begin(),(a).end()
#define endl '\n'
void shiro_oni()
{
    int n; 
    cin >> n;
    vector<int> a(n);
    for(auto &x : a) cin >> x;
    vector<int> lis;
    for(int x : a) {
        auto it = lower_bound(all(lis), x);
        if(it == lis.end()) {
            lis.push_back(x);
        } else {
            *it = x;
        }
    }

    cout << lis.size() << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    shiro_oni();
    return 0;
}
//https://cses.fi/problemset/task/1145/
