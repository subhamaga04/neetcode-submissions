class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maximum = INT_MIN; 
        int sum = 0; 
        for(auto &it : nums){
            sum += it; 
            maximum = max(sum, maximum); 
            sum = max(sum, 0); 
        }
        return maximum; 
    }
};
