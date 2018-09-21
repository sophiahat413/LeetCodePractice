class Solution {
public:
    int numWays(int n, int k) {
        if(n <= 1 && k >= 0)
            return n*k;
        vector<int> dp1(n, 0);
        vector<int> dp2(n, 0);
        //dp1 -> the last two feneces are same
        //dp2 -> the last two fences are different
        //total = dp1[i] + dp2[i]
        dp1[1] = k;
        dp2[1] = k * (k-1);
        for(int i = 2; i < n; i++){
            dp1[i] = dp2[i-1];
            dp2[i] = (k-1) * (dp1[i-1] + dp2[i-1]); 
        }
        return dp1[n-1]+dp2[n-1];
    }
};
