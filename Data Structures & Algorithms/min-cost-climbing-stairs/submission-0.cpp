class Solution {
   private:
    int func(vector<int>& cost, vector<int>& dp, int n) {
        if (n == 0 || n == 1) {
            return cost[n];
        }

        if (dp[n] != -1) {
            return dp[n];
        }

        dp[n] = cost[n] + min(func(cost, dp, n - 1), func(cost, dp, n - 2));

        return dp[n];
    }

   public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size(), -1);
        return min(func(cost, dp, cost.size() - 1), func(cost, dp, cost.size() - 2));
    }
};
