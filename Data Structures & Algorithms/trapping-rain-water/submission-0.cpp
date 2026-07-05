class Solution {
public:
    int trap(vector<int>& height) {
        // this is a solution with O(n) space complexity lekin time complexity hai O(n)
        int n = height.size(); 
        vector<int> max_left(n,0); 
        vector<int> max_right(n,0); 

        int left_max = 0; 
        for(int i = 0; i < n; i++){
            max_left[i] = left_max; 
            if(left_max < height[i]) left_max = height[i]; 
        }

        int right_max = 0; 
        for(int i = n-1; i >= 0; i--){
            max_right[i] = right_max; 
            if(right_max < height[i]) right_max = height[i]; 
        }

        int total_units = 0; 
        for(int i = 0; i < n; i++){
            int unit = min(max_left[i], max_right[i]) - height[i]; 
            if(unit > 0){
                total_units += unit; 
            }
        }

        return total_units; 
    }
};
