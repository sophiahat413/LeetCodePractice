class Solution {
public:
    int grid(int i, int q){
        int l, r;
        l = i / 3;
        r = q / 3;
        int idx = l * 3 + r;
        return idx;  
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<int>> mp(27, vector<int>(9, 0));
        for(int i = 0; i < board.size(); i++){
            for(int q = 0; q < board.size(); q++){
                if(board[i][q] == '.')
                    continue;
                int idx = board[i][q] - '1';
                mp[i][idx]++;
                if(mp[i][idx] >= 2)
                    return false;
                mp[q+9][idx]++;
                if(mp[q+9][idx] >= 2)
                    return false;
                int tmp = grid(i, q);
                mp[tmp+18][idx]++;
                if(mp[tmp+18][idx] >= 2)
                    return false;
            }
        }
        return true;
    }
};
