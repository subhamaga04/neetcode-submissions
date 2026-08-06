class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size(); 
        vector<bool> dp(n+1, false); 
        unordered_map<string, int> mp; 

        for(auto &it : wordDict){
            mp[it]++; 
        }

        dp[0] = true; 

        for(int i = 0; i <= s.size(); i++){
           for(int j = 0; j < i; j++){
                if(dp[j] && mp.find(s.substr(j, i - j)) != mp.end()){
                    dp[i] = true; 
                    
                }
           }
        }

        return dp[n]; 
    }
};
