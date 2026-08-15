class Solution {
private: 
    int solve(vector<int> &nums,  vector<vector<int>> &dp, int left, int right){

        if(left > right){
            return 0; 
        }

        if(dp[left][right] != -1) return dp[left][right]; 

        int max_coins = INT_MIN; 
        for(int k = left; k <= right; k++){
            int coins = (nums[left-1] * nums[k] * nums[right+1]) + solve(nums, dp, left, k-1) + solve(nums, dp, k+1, right); 
            max_coins = max(max_coins, coins); 
        }

        return dp[left][right] = max_coins; 
    }
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size(); 
        vector<vector<int>> dp(n+1, vector<int> (n+1, -1)); 
        nums.insert(nums.begin(), 1); 
        nums.push_back(1); 

        return solve(nums, dp, 1, n); 
    }
};
