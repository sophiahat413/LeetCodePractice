class Solution {
public:
    int minDistance(string word1, string word2) {
        int l1 = word1.length(), l2  = word2.length();
        dp = vector<vector<int>>(l1+1, vector<int>(l2+1, -1));
        return minDistance(l1, l2, word1, word2);
    }
private:
    vector<vector<int>> dp;
    int minDistance(int l1, int l2, string &word1, string &word2){
        if(l1 == 0) return l2;
        if(l2 == 0) return l1;
        if(dp[l1][l2] >= 0) return dp[l1][l2];
        int ans;
        if(word1[l1-1] == word2[l2-1])
            ans = minDistance(l1-1, l2-1, word1, word2);
        else
            ans = min(minDistance(l1-1, l2, word1, word2), min(minDistance(l1-1, l2-1, word1, word2), minDistance(l1, l2-1, word1, word2))) + 1;
        return dp[l1][l2] = ans;
    }
};
