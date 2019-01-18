class Solution {
private: 
    int use1[9][9];
    int use2[9][9];
    int use3[9][9];
public:
    void solveSudoku(vector<vector<char>>& board) {
        //use1[9][9] = {0}, use2[9][9] = {0}, use3[9][9] = {0};
        for(int i = 0; i < 9; i++){
            for(int q = 0; q < 9; q++){
                if(board[i][q] != '.'){
                    int num = board[i][q] - '1';
                    int bx = i / 3, by = q / 3;
                    use1[i][num] = 1;
                    use2[q][num] = 1;
                    use3[bx * 3 + by][num] = 1;
                }
            }
        }
        fill(board, 0, 0);
    }
    bool fill(vector<vector<char>>& board, int x, int y){
        if(y == 9)  return true;
        int nx = (x + 1) % 9;
        int ny = (nx == 0) ? y+1 : y;
        if(board[x][y] != '.')  return fill(board, nx, ny);
        int bx = x / 3, by = y / 3;
        for(int i = 0; i < 9; i++){
            if(!use1[x][i] && !use2[y][i] && !use3[bx * 3 + by][i]){
                use1[x][i] = use2[y][i] = use3[bx * 3 + by][i] = 1;
                board[x][y] = i + '1';
                if(fill(board, nx, ny)) return true;
                use1[x][i] = use2[y][i] = use3[bx * 3 + by][i] = 0;
                board[x][y] = '.';
            }
        }
        return false;
    }
};
