class Solution {
private: 
    int func(vector<int> &nums, vector<int> &dp, int i){
        if(i == 0){
            return nums[i]; 
        }

        if(dp[i] != -1) return dp[i]; 

        int a = 0; 
        if(i-2 >= 0){
            a = func(nums, dp, i - 2);
        }
        int b = 0; 
        if(i -3 >=0){
            b = func(nums,dp, i - 3); 
        }

        return dp[i] = nums[i] + max(a,b); 
        
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];  
        vector<int> dp(n, -1); 
        int lst = func(nums, dp, n-1); 
        int second_lst = func(nums, dp, n-2); 
        return max(lst, second_lst); 
    }
};
