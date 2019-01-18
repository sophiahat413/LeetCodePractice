class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
        }
        if(sum % 2)
            return false;
        vector<int> dp(sum+1, 0);
        dp[0] = 1;
        for(int i = 0; i < nums.size(); i++){
            for(int q = sum; q >= 0; q--){
                if(dp[q])
                    dp[q + nums[i]] = 1;
                if(dp[sum / 2]) return true;
            }
        }
        return false;
    }
};
