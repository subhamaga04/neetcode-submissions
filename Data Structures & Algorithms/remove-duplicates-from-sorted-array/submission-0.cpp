class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 1; 
        int replace = 1; 
        if(nums.size()==1) return k; 
        for(int i = 1; i< nums.size(); i++){
            if(nums[i] != nums[i-1]){
                nums[replace] = nums[i]; 
                replace++; 
                k++; 
            }
        }
        return k; 
    }
};