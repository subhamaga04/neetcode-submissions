class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size(); 
        if(n < 2) return s; 
        int max_length = 1; 
        int start_index = 0; 
        vector<vector<bool>> dp(n+1, vector<bool> (n+1, false)); 

        for(int i = 0; i < n; i++){
            dp[i][i] = true; 
        }

        for(int i = 0; i < n - 1; i++){
            if(s[i] == s[i+1]){
                dp[i][i+1] = true; 
                max_length = 2; 
                start_index = i; 
            }
        }

        for(int len = 3; len <= n; len++){
            for(int i = 0; i <= n - len; i++){
                int j = i + len - 1; 
                if(s[i] == s[j] && dp[i+1][j-1]){
                    dp[i][j] = true; 
                    start_index = i; 
                    max_length = len; 
                }
            }
        }
        
        return s.substr(start_index, max_length); 
    }
};
