class Solution {
public:
    int find(vector<vector<int>>& grid, int x, int y){
       if(x >= 0 && x <grid.size() && y >= 0 && y < grid[0].size() && grid[x][y] == 1){
           grid[x][y] = 0;
           return 1 + find(grid, x-1, y) + find(grid, x+1, y) + find(grid, x, y-1) + find(grid, x, y+1);
       }
       return 0;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int MaxArea = 0;
        for(int i = 0; i<grid.size(); i++){
            for(int q = 0; q<grid[i].size(); q++){
                if(grid[i][q] == 1){
                    MaxArea = max(MaxArea, find(grid, i, q));
                }
            }
        }
        return MaxArea;
    }
};
