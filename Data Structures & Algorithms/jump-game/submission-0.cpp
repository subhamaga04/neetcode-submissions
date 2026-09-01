class Solution {
private: 
    int solve(vector<int> &nums, vector<int> &dp, int i, int n){

        if(i >= n -1) {
            return true; 
        }

        if(dp[i] != -1) return dp[i]; 

        for(int j = i+1; j <= i + nums[i] && j < n; j++){
            if(solve(nums, dp, j, n)){
                return dp[i] = true; 
            }
        }

        return dp[i] = false; 
    }
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size(); 
        if(n == 1) return true; 
        if(nums[0] == 0) return false; 
        vector<int> dp(n+1, -1); 
        return solve(nums, dp, 0, n); 

    }
};
