class Solution {
private:
    void set(int index, vector<vector<int>> &arr1, vector<int> &arr, vector<int> &nums){
        arr1.push_back(arr); 
        if(index >= nums.size()){
            
            return; 
        }

        for(int i = index ; i < nums.size(); i++){
            if(i > index && nums[i] == nums[i-1]){
                continue; 
            }
            arr.push_back(nums[i]); 
            set(i+1, arr1, arr, nums); 
            arr.pop_back(); 
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> arr1; 
        vector<int> arr; 
        sort(nums.begin(), nums.end()); 
        set(0, arr1, arr, nums); 
        return arr1; 
    }
};
