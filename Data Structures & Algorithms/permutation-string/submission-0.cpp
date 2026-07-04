class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false; 
        vector<int> s1freq(26,0); 
        vector<int> winfreq(26,0); 

        for(int i = 0; i < s1.size(); i++){
            s1freq[s1[i] -'a']++; 
            winfreq[s2[i]-'a']++; 
        }

        int left = 0; 
        int right = s1.size()-1; 

        while(right < s2.size()){
            if(s1freq == winfreq) return true; 

            winfreq[s2[left] - 'a']--; 
            left++; 
            right++; 
            if(right < s2.size()) winfreq[s2[right]-'a']++; 
        }

        return false; 
    }
};
