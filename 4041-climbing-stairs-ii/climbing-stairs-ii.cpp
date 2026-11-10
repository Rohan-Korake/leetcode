class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<long long> dp(n + 1, LLONG_MAX);
        dp[0] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = max(0, i - 3); j < i; ++j) {
                long long jumpCost = dp[j] + costs[i - 1] + (i - j) * (i - j);
                dp[i] = min(dp[i], jumpCost);
            }
        }
        return dp[n];
    }
};