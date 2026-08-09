class Solution {
private: 
    int solve(vector<int>& prices, int i, int buy,  vector<vector<int>> &dp){
        if(i >= prices.size()){
            return 0; 
        }

        if(dp[i][buy] != -1) return dp[i][buy]; 

        if(buy == 1){
            int choice_1 = - prices[i] + solve(prices, i + 1, 0, dp); 
            int choice_2 = 0 + solve(prices, i + 1, 1, dp); 
            return dp[i][buy] = max(choice_1, choice_2); 
        }else{
            int choice_3 = prices[i] + solve(prices, i+2, 1, dp); 
            int choice_4 = 0 + solve(prices, i+1, 0, dp); 
            return max(choice_3, choice_4); 
        }

        return -1; 
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(); 
        vector<vector<int>> dp(n, vector<int> (2, -1)); 
        return solve(prices, 0, 1, dp); 
    }
};
