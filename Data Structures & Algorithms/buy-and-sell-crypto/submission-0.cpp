class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int start = 0; 
        int maxi = 0; 
        for(int end = 0; end < prices.size(); end++){
            if(prices[end] < prices[start]){
                start = end;
            }
            int profit = prices[end] - prices[start]; 
            maxi = max(maxi, profit); 
        }
        return maxi; 
    }
};
