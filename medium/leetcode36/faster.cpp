class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int used1[9][9] = {0}, used2[9][9] = {0}, used3[9][9] = {0};
        for(int i = 0; i < board.size(); i++){
            for(int q = 0; q < board.size(); q++){
                if(board[i][q] != '.'){
                    int num = board[i][q] - '1', k = (i / 3) * 3 + q / 3;
                    if(used1[i][num] || used2[q][num] || used3[k][num])
                        return false;
                    used1[i][num] = used2[q][num] = used3[k][num] = 1;
                }
            }
        }
        return true;
    }
};
