class Solution {
private:     
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size() == 1) return; 
        int right = nums.size()-2; 
        int breakpoint = -1; 
        while(right > 0){
            if(nums[right] < nums[right+1]){
                breakpoint = right; 
                break; 
            }else right--; 
        }
        if(breakpoint == -1){
            reverse(nums.begin(), nums.end()); 
            return; 
        }
        right = nums.size()-1; 
        int swap_element = 0; 
        while(right > breakpoint){
            if(nums[right] > nums[breakpoint]){
                swap_element = right;
                break; 
            }else right--; 
        }
        swap(nums[breakpoint], nums[swap_element]); 
        reverse(nums.begin()+breakpoint+1, nums.end()); 
    }
};