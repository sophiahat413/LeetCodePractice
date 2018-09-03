class Solution {
public:
    void find(vector<vector<int>>& grid, int x, int y, int& area){
        if(grid[x][y] == 1){
            grid[x][y] = 0;
            area++;
            if(x != 0)
                find(grid, x-1, y, area);
            if(x != grid.size()-1)
                find(grid, x+1, y, area);
            if(y != 0)
                find(grid, x, y-1, area);
            if(y != grid[0].size()-1)
                find(grid, x, y+1, area);
        }
        else
            return;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int MaxArea = 0;
        for(int i = 0; i<grid.size(); i++){
            for(int q = 0; q<grid[i].size(); q++){
                if(grid[i][q] == 1){
                    int area = 0;
                    find(grid, i, q, area);
                    MaxArea = max(MaxArea, area);
                }
            }
        }
        return MaxArea;
    }
};
