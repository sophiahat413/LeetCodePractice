class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        if(costs.size() == 0)
            return 0;
        if(costs[0].size() == 1)
            return costs[0][0];
        int H = costs.size();
        int k = costs[0].size();
        int lastUsedColor = -1, preLastUsedColor = -1;
        vector<vector<int>> dp(H, vector<int>(k, 0));
        for(int i = 0; i < H; i++){
            int newColor = -1, lastNewColor = -1;
            int m1 = INT_MAX, m2 = INT_MAX;
            for(int q = 0; q < k; q++){
                if(q == lastUsedColor)
                    dp[i][q] = ((i > 0) ? dp[i-1][preLastUsedColor] : 0) + costs[i][q];
                else
                    dp[i][q] = ((i > 0) ? dp[i-1][lastUsedColor] :0) + costs[i][q];
                 //set the first and second smallest
                if(dp[i][q] < m1){
                    lastNewColor = newColor;
                    newColor = q;
                    m2 = m1;
                    m1 = dp[i][q];
                }
                else if(dp[i][q] < m2){
                    lastNewColor = q;
                    m2 = dp[i][q];
                }
                //cout<<m1<<" "<<m2<<endl;
            }
            lastUsedColor = newColor;
            preLastUsedColor = lastNewColor;
        }
        return dp[H-1][lastUsedColor];
    }
};
