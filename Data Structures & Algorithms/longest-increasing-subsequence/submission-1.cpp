class Solution {
private: 
    int find(vector<int> &nums, int i, int p,  vector<vector<int>> &dp){
        if(i == nums.size()){
            return 0; 
        }

        if(p!=-1 && dp[i][p] != -1) return dp[i][p]; 

        int a = 0; 
        if(p == -1 || nums[i] > nums[p]){
            a = 1 + find(nums, i+1,i,dp);
        }

        int b = find(nums, i+1,p,dp); 

        if(p != -1){
            return dp[i][p] = max(a,b); 
        }

        return max(a,b);
        
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size(); 
        vector<vector<int>> dp(n+1, vector<int> (n+1, -1));  
        return find(nums, 0, -1, dp); 
    }

};