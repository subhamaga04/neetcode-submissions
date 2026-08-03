class Solution {
private: 
    int find(vector<int> &dp, string &s, int i){
        if(i == s.size()){
            return dp[i] = 1; 
        }
        
        if(dp[i] != -1) return dp[i]; 

        if(s[i] == '0') return dp[i] = 0; 

        int a = find(dp, s, i+1); 
        int b = 0; 
        if(i + 1 < s.size()){
            if(s[i] == '1' || (s[i] == '2' && s[i+1] <= '6')){
                b = find(dp, s, i+2); 
            }
        }

        return dp[i] = a + b; 

    }
public:
    int numDecodings(string s) {
        vector<int> dp(101, -1); 

        return find(dp, s, 0); 
    }
};
