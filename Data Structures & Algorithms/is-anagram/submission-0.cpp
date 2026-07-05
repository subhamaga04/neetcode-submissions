class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false; 
        vector<int> s1(26,0); 
        vector<int> s2(26,0); 

        for(int i = 0; i < s.size(); i++){
            s1[s[i] - 'a']++; 
            s2[t[i] - 'a']++; 
        }

        if(s1 == s2) return true; 
        return false; 
    }
};
