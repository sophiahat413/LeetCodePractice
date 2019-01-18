class Solution {
public:
    int profitableSchemes(int G, int P, vector<int>& group, vector<int>& profit) {
        int kMod = 1000000007;
        int K = group.size();
        long res = 0;
        vector<vector<int>> dp(P+1, vector<int>(G+1, 0));
        dp[0][0] = 1;
        for(int k = 1; k <= K; k++){
            auto tmp = dp;
            int p = profit[k-1];
            int g = group[k-1];
            for(int i = 0; i <= P; i++){
                for(int j = 0; j <= G; j++){
                    tmp[i][j] = (tmp[i][j] + (j < g ? 0 : dp[max(0, i-p)][j-g])) % kMod;
                }
            }
            dp.swap(tmp);
        }
        for(int i = 0; i < dp[P].size(); i++){
            res = (res + dp[P][i]) % kMod;
        }
        return res;
    }
};
