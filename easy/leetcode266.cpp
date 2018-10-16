class Solution {
public:
    bool canPermutePalindrome(string s) {
        vector<int> alpha(256, 0);
        int res = 0, i;
        for(i = 0; i < s.length(); i++){
            alpha[s[i] - '\0']++;
        }
        for(i = 0; i < alpha.size(); i++){
            if(res % 2){
                if(alpha[i] % 2)
                    return false;
            }
            res += alpha[i];
        }
        return true;
    }
};
