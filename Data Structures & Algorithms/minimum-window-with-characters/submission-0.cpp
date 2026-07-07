class Solution {
   private: 
    bool valid(vector<int> &tf, vector<int> &wf){
            for(int i = 0; i<52; i++){
                if(wf[i] < tf[i]) return false; 
            }
            return true; 
        }
   public:
    string minWindow(string s, string t) {
        if(s.empty() || t.empty() || s.size() < t.size()) return ""; 
        vector<int> tf(52, 0);
        vector<int> wf(52, 0);

        for (int i = 0; i < t.size(); i++) {
            if (t[i] >= 'A' && t[i] <= 'Z') {
                tf[t[i] - 'A']++;
            } else {
                tf[(t[i] - 'a') + 26]++;
            }
        }

        int left = 0;
        int right = 0;
        int min_len = INT_MAX; 
        int start = -1; 
        while (right < s.size()) {
            if (s[right] >= 'A' && s[right] <= 'Z') {
                wf[s[right] - 'A']++;
            } else {
                wf[(s[right] - 'a') + 26]++;
            }

            while (valid(tf, wf)) {
                int length = right - left + 1;
                if (length < min_len) {
                    min_len = length;
                    start = left;
                }
                if (s[left] >= 'A' && s[left] <= 'Z') {
                    wf[s[left] - 'A']--;
                } else {
                    wf[(s[left] - 'a') + 26]--;
                }

                left++; 
            }
            right++; 
        }

        if(start == -1) return ""; 

        return s.substr(start, min_len); 
    }
};
