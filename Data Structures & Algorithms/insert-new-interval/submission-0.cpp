class Solution {
   private:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); i++) {
            if (ans.back()[1] >= intervals[i][0]) {
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            } else {
                ans.push_back(intervals[i]);
            }
        }
        return ans; 
    }

   public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result; 
        bool insertt = false; 
        for(int i = 0; i < intervals.size(); i++){
            if(!insertt && intervals[i][0] >= newInterval[0]){
                result.push_back(newInterval); 
                insertt = true; 
            }

            result.push_back(intervals[i]); 
        }

        if(!insertt){
            result.push_back(newInterval); 
        }

        return merge(result); 
    }
};
