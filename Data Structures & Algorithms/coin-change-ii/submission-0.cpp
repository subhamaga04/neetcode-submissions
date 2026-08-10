class Solution {
   private:
    int solve(int target, vector<int>& coins, int i, vector<vector<int>>& dp) {
        if (target == 0) {
            return 1;
        }

        if (target < 0 || i >= coins.size()) {
            return 0;
        }

        if (dp[i][target] != -1) return dp[i][target];

        int take = solve(target - coins[i], coins, i, dp);
        int skip = solve(target, coins, i + 1, dp);

        return dp[i][target] = take + skip;
    }

   public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount+1, -1));
        return solve(amount, coins, 0, dp);
    }
};
