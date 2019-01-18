class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.empty())  return {};
        int m = matrix.size(), n = matrix[0].size();
        vector<int> res(m * n);
        int l = 0, r = n-1, u = 0, d = m-1, idx = 0;
        while(true){
            for(int col = l; col <= r; col++)   res[idx++] = matrix[u][col];
            if(++u > d) break;
            for(int row = u; row <= d; row++)   res[idx++] = matrix[row][r];
            if(--r < l) break;
            for(int col = r; col >= l; col--)   res[idx++] = matrix[d][col];
            if(--d < u) break;
            for(int row = d; row >= u; row--)   res[idx++] = matrix[row][l];
            if(++l > r) break;
        }
        return res;
    }
};
