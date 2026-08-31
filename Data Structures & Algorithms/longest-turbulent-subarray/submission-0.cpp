class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size(); 
        if(n == 1) return 1; 
        int left = 0; 
        int right = 0; 
        int max_length = 0; 

        for(int k = 0; k < n - 1; k++){
            if(k % 2 == 0){
                if(arr[k] >= arr[k+1]){
                    left = k+1; 
                    right = k+1; 
                }else{
                    right++; 
                }
            }else{
                if(arr[k] <= arr[k+1]){
                    left = k+1; 
                    right = k+1; 
                }else{
                    right++; 
                }
            }

            int length = right - left + 1; 
            max_length = max(max_length, length); 
        }

        left = 0;
        right = 0; 
        for(int k = 0; k < n - 1; k++){
            if(k % 2 != 0){
                if(arr[k] >= arr[k+1]){
                    left = k+1; 
                    right = k+1; 
                }else{
                    right++; 
                }
            }else{
                if(arr[k] <= arr[k+1]){
                    left = k+1; 
                    right = k+1; 
                }else{
                    right++; 
                }
            }

            int length = right - left + 1; 
            max_length = max(max_length, length); 
        }


        return max_length; 
    }
};