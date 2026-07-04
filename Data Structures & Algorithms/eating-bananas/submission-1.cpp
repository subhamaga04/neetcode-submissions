class Solution {
public:
    bool check(vector<int>& piles, int h, int mid){
        int total_hours = 0; 
        for(int pile : piles){
            total_hours += (pile + mid - 1) / mid; 
        }
        return total_hours <= h; 
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1; 
        int high = *max_element(piles.begin(), piles.end()); 
        int minima = 0; 
        while(low <= high){
            int mid = low + (high-low)/2; 
            if(check(piles, h, mid)){
                minima = mid; 
                high = mid -1; 
            }else{
                low = mid + 1; 
            }
        }
        return minima; 

    }
};
