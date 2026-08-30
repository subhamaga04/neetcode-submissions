class Solution {
private: 
    int minima(vector<int> &nums){
        int n = nums.size(); 
        int sum = 0; 
        int minimum = INT_MAX; 
        for(int i = 0; i < n; i++){
            sum += nums[i]; 
            minimum = min(sum, minimum); 
            sum = min(sum, 0); 
        }
        return minimum; 
    }

    int maxima(vector<int> &nums){
        int n = nums.size(); 
        int sum = 0; 
        int maximum = INT_MIN; 
        for(int i = 0; i < n; i++){
            sum += nums[i]; 
            maximum = max(sum, maximum); 
            sum = max(sum, 0); 
        }
        return maximum; 
    }
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int total_sum = accumulate(nums.begin(), nums.end(), 0); 
        int max_subarray_sum = maxima(nums); 
        int min_subarray_sum = minima(nums); 
        if(max_subarray_sum > 0){
            return max(max_subarray_sum, total_sum - min_subarray_sum); 
        }
        return max_subarray_sum; 
    }
};