class Solution {
public:
    int profitableSchemes(int G, int P, vector<int>& group, vector<int>& profit) {
        int kMod = 1000000007;
        int K = group.size();
        long res = 0;
        vector<vector<vector<int>>> dp(K+1, vector<vector<int>>(P+1, vector<int>(G+1, 0)));
        dp[0][0][0] = 1;
        for(int k = 1; k <= K; k++){
            int p = profit[k-1];
            int g = group[k-1];
            for(int i = 0; i <= P; i++){
                for(int j = 0; j <= G; j++){
                    dp[k][i][j] = (dp[k-1][i][j] + (j < g ? 0 : dp[k-1][max(0, i-p)][j-g])) % kMod;
                }
            }
        }
        for(int i = 0; i < dp[K][P].size(); i++){
            res = (res + dp[K][P][i]) % kMod;
        }
        return res;
    }
};
