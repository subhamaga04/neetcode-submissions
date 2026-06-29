class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> arr; 
        int left = 0; 
        int right = nums.size() -1; 

        while(left < right){
            if(nums[left] + nums[right] == target){
                arr.push_back(left+1); 
                arr.push_back(right+1); 
                break; 
            }else if(nums[left] + nums[right] > target){
                right--; 
            }else left++; 
        }

        return arr; 
    }
};
