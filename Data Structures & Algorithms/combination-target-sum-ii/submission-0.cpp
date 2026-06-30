class Solution {
public:
    void combi(int index, vector<int>& candidates, vector<int>& arr, vector<vector<int>>& arr1, int target){
        if(target == 0){
            arr1.push_back(arr); 
            return;
        }

        if(target < 0 && index >= candidates.size()){
            return; 
        }

        for(int i = index; i< candidates.size(); i++){

            if(i > index &&  candidates[i] == candidates[i-1]){
                continue; 
            }

            if(candidates[i] > target){
                break; 
            }

            arr.push_back(candidates[i]); 
            combi(i+1, candidates, arr, arr1, target - candidates[i]); 
            arr.pop_back(); 
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> arr; 
        vector<vector<int>> arr1; 
        sort(candidates.begin(), candidates.end()); 
        combi(0, candidates, arr, arr1, target); 

        return arr1; 
    }
};
