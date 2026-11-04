#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m; cin>>n>>m;

    vector<vector<int>> adj(n + 1);
    vector<int> indegree(n + 1, 0);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        indegree[v]++;
    }

    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) {
            pq.push(i);
        }
    }

    vector<int> ans;
    while (!pq.empty()) {
        int u = pq.top();
        pq.pop();
        ans.push_back(u);

        for (int v : adj[u]) {
            if (--indegree[v] == 0) {
                pq.push(v);
            }
        }
    }

    if ((int)ans.size() != n) {
        cout << -1 << "\n"; // Cycle detected
    } else {
        for (int i = 0; i < n; i++) {
            cout << ans[i] << (i == n - 1 ? "" : " ");
        }
        cout << "\n";
    }

    return 0;
}