class Solution {
private: 
    bool solve(vector<vector<int>> &dp, vector<int> &nums, int i , int target){
        if(target == 0){
            return true; 
        }

        if(i >= nums.size() || target < 0) return false; 

        if(dp[i][target] != -1) return dp[i][target]; 

        bool a = solve(dp, nums, i+1, target - nums[i]); 
        bool b = solve(dp, nums, i+1, target); 

        return dp[i][target] = a||b; 
        }
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size(); 
        int sum = accumulate(nums.begin(), nums.end(),  0); 
       

        if(sum % 2 != 0) return false; 

        int target = sum / 2; 
        vector<vector<int>> dp(n, vector<int> (target+1, -1)); 
        return solve(dp, nums, 0, target);  
    }
};
