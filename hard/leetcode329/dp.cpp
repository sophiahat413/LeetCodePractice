class Solution {
int rows, cols;
vector<vector<int>> dp;
public:
    
    int dfs(vector<vector<int>>&matrix, int x, int y){
        if(dp[x][y] > 0)
            return dp[x][y];
        int res = 1;
        if(x-1 >= 0 && matrix[x-1][y] > matrix[x][y])
            res = max(res, 1 + dfs(matrix, x-1, y));
        if(x+1 < rows && matrix[x+1][y] > matrix[x][y])
            res = max(res, 1 + dfs(matrix, x+1, y));
        if(y-1 >= 0 && matrix[x][y-1] > matrix[x][y])
            res = max(res, 1+ dfs(matrix, x, y-1));
        if(y+1 < cols && matrix[x][y+1] > matrix[x][y])
            res = max(res, 1 + dfs(matrix, x, y+1));
        dp[x][y] = res;
        return dp[x][y];
    }
   
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.size() == 0)
            return 0;
        rows = matrix.size();
        cols = matrix[0].size();
        dp = vector<vector<int>>(rows, vector<int>(cols, 0));
        int res = 0;
        for(int i = 0; i<rows; i++){
            for(int q = 0; q<cols; q++)
                res = max(res, dfs(matrix, i, q));
        }
        return res;
    }
};
