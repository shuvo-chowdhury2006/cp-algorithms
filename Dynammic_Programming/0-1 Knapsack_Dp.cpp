#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
vector<vector<int>> dp(N, vector<int>(N, -1));
vector<int> val(N), weight(N);
int knapsack(int i, int mx_weight)
{
    if (i < 0 || mx_weight <= 0)
        return 0;
    if (dp[i][mx_weight] != -1)
        return dp[i][mx_weight];
    if (weight[i] <= mx_weight)
    {
        int op1 = knapsack(i - 1, mx_weight - weight[i]) + val[i];
        int op2 = knapsack(i - 1, mx_weight);
        dp[i][mx_weight] = max(op1, op2);
        return dp[i][mx_weight];
    }
    else
    {
        dp[i][mx_weight] = knapsack(i - 1, mx_weight);
        return dp[i][mx_weight];
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, mx_weight;
    cin >> n >> mx_weight;
    for (int i = 0; i < n; i++)
    {
        cin >> weight[i] >> val[i];
    }
    cout << knapsack(n - 1, mx_weight) << endl;
}
