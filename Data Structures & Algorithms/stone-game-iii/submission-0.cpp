class Solution {
private: 
    int solve(vector<int>& stone,  vector<int> &dp, int i, int n){
        if(i >= n) return 0; 

        if(dp[i] != -1) return dp[i]; 

        int result = INT_MIN; 

        result = max(result, stone[i] - solve(stone, dp, i+1, n)); 
        if(i+1 < n)
            result = max(result, stone[i] + stone[i+1] - solve(stone, dp, i+2, n)); 
        if(i+2 < n){
            result = max(result, stone[i] + stone[i+1] + stone[i+2] - solve(stone, dp, i+3, n)); 
        }

        return dp[i] = result; 
    }
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size(); 
        vector<int> dp(n, -1); 
        if(solve(stoneValue, dp, 0, n) > 0) return "Alice"; 
        else if(solve(stoneValue, dp, 0, n) < 0) return "Bob"; 
         
        return "Tie"; 
    }
};