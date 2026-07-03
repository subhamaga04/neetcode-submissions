class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0; 
        int right = heights.size() -1;
        int maxi = 0; 
        while(left < right){
            int area = (right-left) * min(heights[right], heights[left]); 
            maxi = max(maxi, area); 
            if(heights[left] <= heights[right]) left++; 
            else right--; 
        }
        return maxi; 
    }
};
