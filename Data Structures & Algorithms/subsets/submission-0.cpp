class Solution {
public:
    void suby(int index, vector<int> &nums, vector<int> &arr, vector<vector<int>> &arr1){
        if(index >= nums.size()){
            arr1.push_back(arr); 
            return; 
        }


        arr.push_back(nums[index]); 
        suby(index+1, nums, arr, arr1); 
        arr.pop_back(); 
        suby(index+1, nums, arr,arr1); 
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> arr;
        vector<vector<int>> arr1; 
        suby(0, nums, arr, arr1); 

        return arr1; 
    }
};
