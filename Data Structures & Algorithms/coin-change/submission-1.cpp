class Solution {
private: 
    int solve(vector<int> &coins, int target, int i, vector<vector<int>> &dp){

        if(target == 0) return 0; 

        if(target < 0 || i >= coins.size()) return 1e9; 

        if(dp[i][target] != -1) return dp[i][target]; 

        int take = 1+ solve(coins, target - coins[i], i, dp); 
        int skip = solve(coins, target, i+1, dp); 

        return dp[i][target] = min(take, skip); 
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size(); 
        vector<vector<int>> dp(n+1, vector<int> (amount+1, -1)); 
        int ans = solve(coins, amount, 0, dp); 
        return ans >= 1e5 ? -1 : ans; 
    }
};
