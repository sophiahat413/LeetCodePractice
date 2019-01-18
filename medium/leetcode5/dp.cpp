//take cosey's code as reference
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if(n == 0)  return "";
        bool P[n][n] = {false};
        for(int i = 0; i < n; i++){
            P[i][i] = true;
            if(i == n-1)    break;
            P[i][i+1] = s[i] == s[i+1];
        }
        for(int i = n - 3; i >= 0; i--){
            for(int j = i+2; j < n; j++)
                P[i][j] = (P[i+1][j-1] && s[i] == s[j]);
        }
        int res = INT_MIN;
        string maxStr;
        for(int i = 0; i < n; i++){
            for(int q = i; q < n; q++){
                if(P[i][q] && q-i+1 > res){
                    res = q - i + 1;
                    maxStr = s.substr(i, res);
                }
            }
        }
        return maxStr;
    }
};




