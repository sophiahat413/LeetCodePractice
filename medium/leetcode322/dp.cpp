class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int Max = amount + 1;
        vector<int> dp(amount+1, Max);
        dp[0] = 0;
        for(int i = 1; i <= amount; i++){
            for(int q = 0; q < coins.size(); q++){
                if(coins[q] <= i){
                    dp[i] = min(dp[i], dp[i-coins[q]]+1);
                }
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
};
