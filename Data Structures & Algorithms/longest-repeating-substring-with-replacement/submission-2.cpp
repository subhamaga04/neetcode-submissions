class Solution {
public:
    bool valid(int l, int r, int maxima, int k){
        if(r-l+1 -maxima <=k) return true; 
        return false; 
    }
    int maxima(vector<int> &tracker){
        int maxi = 0; 
        for(int i = 0; i<26; i++){
            maxi = max(maxi, tracker[i]); 
        }

        return maxi; 
    }
    int characterReplacement(string s, int k) {
        vector<int> tracker(26, 0); 
        int left = 0; 
        int right = 0; 
        int max_length = 0; 
        while(right < s.size()){
            tracker[s[right] -'A']++; 
            while(!valid(left, right, maxima(tracker), k)){
                tracker[s[left] - 'A']--; 
                left++; 
            }
            int length = right - left + 1;
            max_length = max(length, max_length); 
            right++; 

        }
        return max_length; 
    }
};
