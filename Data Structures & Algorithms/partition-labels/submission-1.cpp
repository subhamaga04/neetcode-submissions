class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size(); 
        unordered_map<char, int> mp; 
        set<char> st; 

        for(char c : s){
            mp[c]++; 
        }
        int sum = 0; 

        vector<int> ans; 

        for(int i = 0; i < n; i++){
            if(st.find(s[i]) == st.end()){
                st.insert(s[i]); 
            }

            mp[s[i]]--; 

            if(mp[s[i]] == 0){
                st.erase(s[i]); 
            }

            if(st.empty()){
                int a = i+1; 
                int b = i+1 - sum; 
                ans.push_back(b); 
                sum += b; 
            }
        }

        return ans; 
    }
};
