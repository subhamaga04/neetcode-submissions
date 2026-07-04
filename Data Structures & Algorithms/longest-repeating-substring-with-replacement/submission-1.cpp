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
        int length = 0; 
        while(right < s.size()){
            tracker[s[right] -'A']++; 
            int frequency = maxima(tracker); 
            if(valid(left, right, frequency, k)){
                length = right - left + 1; 
                right++; 
            }else{
                tracker[s[left] - 'A']--; 
                left++; 
                right++; 
            }
        }
        return length; 
    }
};
