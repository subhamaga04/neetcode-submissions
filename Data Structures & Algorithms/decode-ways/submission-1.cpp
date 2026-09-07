class Solution {
private: 
    int solve(vector<int> &dp, string &s, int i){
        if(i == s.size()){
            return 1; 
        }
        
        if(s[i] == '0'){
            return 0;
        }

        if(dp[i] != -1) return dp[i]; 


        dp[i] = 0; 

        dp[i] += solve(dp, s, i+1); 
        
        if(i+1 < s.size() && (s[i] == '1' || (s[i] == '2' && s[i+1] <= '6'))){
            dp[i] += solve(dp, s, i+2); 
        }

        return dp[i]; 
    }
public:
    int numDecodings(string s) {
        vector<int> dp(s.size() + 1, -1); 
        return solve(dp, s, 0); 
    }
};
