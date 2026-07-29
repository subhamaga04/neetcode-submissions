class Solution {
   public:
    int calc(int n, vector<int>& store) {
        if (n <= 1) return 1;
        if (store[n] != -1) return store[n];

        return store[n] = calc(n - 1, store) + calc(n - 2, store);
    }

    int climbStairs(int n) { 
        vector<int> store(n + 1, -1); 
        return calc(n, store); 
    }
};
