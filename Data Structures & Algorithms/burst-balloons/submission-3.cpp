class Solution {
private: 
    int solve(vector<int> &nums, int left, int right,  vector<vector<int>> &dp){
        if(left > right){
            return 0; 
        }

        if(dp[left][right] != -1) return dp[left][right]; 

        int max_coins = INT_MIN; 
        for(int k = left; k <= right; k++){
            int coin = nums[left-1] * nums[k] * nums[right+1] + solve(nums, left, k-1,dp) + solve(nums, k+1, right,dp) ;
            max_coins = max(max_coins, coin); 
        }

        return dp[left][right] = max_coins; 
    }

public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size(); 
        nums.insert(nums.begin(), 1); 
        nums.push_back(1); 
        vector<vector<int>> dp(n+1, vector<int> (n+1, -1)); 

        return solve(nums, 1, n, dp); 
    }
};
