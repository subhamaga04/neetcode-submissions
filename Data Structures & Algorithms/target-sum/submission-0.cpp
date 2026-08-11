class Solution {
private: 
    int solve(vector<int>& nums, int target, vector<vector<int>> &dp, int totalsum, int i){
        if(i >= nums.size()){
            if(target == 0){
                return 1; 
            }
            return 0; 
        }

        int shifted_target = target + totalsum; 
        if(shifted_target < 0 || shifted_target > 2*totalsum) return 0; 
        if(dp[i][shifted_target] != -1) return dp[i][shifted_target]; 

        int add = solve(nums, target - nums[i], dp, totalsum, i+1); 
        int minus = solve(nums, target + nums[i], dp, totalsum, i+1);

        return dp[i][shifted_target] = add + minus; 
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size(); 
        int totalsum = accumulate(nums.begin(), nums.end(), 0); 
        if(totalsum < abs(target)) return 0; 
        vector<vector<int>> dp(n, vector<int> (2*totalsum+1, -1));

        return solve(nums, target, dp, totalsum, 0);  
    }
};
