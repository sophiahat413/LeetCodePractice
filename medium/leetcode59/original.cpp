class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n));
        int l = 0, r = n-1, u = 0, d = n-1, row, col, cnt = 1;
        while(true){
            for(col = l; col <= r; col++)
                res[u][col] = cnt++;
            if(++u > d) break;
            for(row = u; row <= d; row++)
                res[row][r] = cnt++;
            if(--r < l) break;
            for(col = r; col >= l; col--)
                res[d][col] = cnt++;
            if(--d < u) break;
            for(row = d; row >= u; row--)
                res[row][l] = cnt++;
            if(++l > r) break;
        }
        return res;
    }
};
