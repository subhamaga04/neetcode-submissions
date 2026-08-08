class Solution {
private: 
    bool solve(int target, vector<int> &nums, int i, vector<vector<int>> &dp){
        if(target == 0){ 
            return true; 
        }
        if(i >= nums.size() || target < 0) return false; 

        if(dp[i][target] != -1){
            return dp[i][target]; 
        }

        bool a = solve(target - nums[i], nums, i+1,dp); 
        
        bool b = solve(target, nums, i+1,dp); 
       

        return dp[i][target] = (a || b); 
       
    }
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size(); 
        int sum = 0; 
        for(int &it : nums){
            sum += it; 
        }
        if(sum % 2 != 0) return false; 

        int target = sum/2; 
        vector<vector<int>> dp(n, vector<int> (target+1, -1)); 

        return solve(target, nums, 0, dp); 
    }
};
