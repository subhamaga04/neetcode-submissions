class Solution {
   private:
    int solve(vector<int>& nums, int left, int right, vector<vector<int>>& dp) {
        if (left > right) {
            return 0;
        }

        if (dp[left][right] != -1) return dp[left][right];

        int max_coins = INT_MIN;
        for (int k = left; k <= right; k++) {
            int coin = nums[left - 1] * nums[k] * nums[right + 1] + solve(nums, left, k - 1, dp) +
                       solve(nums, k + 1, right, dp);
            max_coins = max(max_coins, coin);
        }

        return dp[left][right] = max_coins;
    }

    int tabulation(vector<int>& nums, vector<vector<int>>& dp, int n) {
        for (int left = n; left > 0; left--) {
            for (int right = left; right <= n; right++) {
                int max_coins = INT_MIN;
                for (int k = left; k <= right; k++) {
                    int coin = nums[left - 1] * nums[k] * nums[right + 1] +
                               dp[left][k - 1] + dp[k + 1][right];
                    max_coins = max(max_coins, coin);
                }

                dp[left][right] = max_coins;

               
            }
        }

        return dp[1][n];
    }

   public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

        // return solve(nums, 1, n, dp);
        return tabulation(nums, dp, n); 
    }
};
