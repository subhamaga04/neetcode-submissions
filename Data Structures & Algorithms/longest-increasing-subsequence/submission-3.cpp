class Solution {
private: 
    int solve(vector<int> &nums, vector<vector<int>> &dp, int i, int prev){
        if(i == nums.size()){
            return 0; 
        }

        if(prev != -1 && dp[i][prev] != -1) return dp[i][prev]; 

        int len = 0; 

        len = solve(nums, dp, i+1, prev);

        if(prev == -1 || nums[i] > nums[prev]){
            len = max(len, 1 + solve(nums, dp, i+1, i)); 
        }

        if(prev != -1) dp[i][prev]= len;

        return len;  
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size(); 
        vector<vector<int>> dp(n+1, vector<int> (n+1, -1)); 
        return solve(nums, dp, 0, -1); 
    }
};
