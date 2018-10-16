class Solution {
public:
    bool helper(vector<vector<char>>& board, vector<vector<int>>& visited, string word, int cur, int x, int y){
        if(x < 0 || y < 0 || x >= board.size() || y >= board[0].size() || visited[x][y] || word[cur] != board[x][y])
            return false;
        if(cur + 1 >= word.length())
            return true;
        visited[x][y] = 1;
        if(helper(board,visited,word,cur+1,x-1,y) || helper(board,visited,word,cur+1,x+1,y) || helper(board,visited,word,cur+1,x,y-1) || helper(board,visited,word,cur+1,x,y+1))
            return true;
        visited[x][y] = 0;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        for(int i = 0; i < board.size(); i++){
            for(int q = 0; q < board[i].size(); q++){
                if(helper(board, visited, word, 0, i, q))
                    return true;
            }
        }
        return false;
    }
};
