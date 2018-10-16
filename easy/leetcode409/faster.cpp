class Solution {
    public:
    int longestPalindrome(string s) {
       if(s.empty())
            return 0;
       int res = 0, i;
       vector<int> alpha(256, 0);
       for(i = 0; i < s.length(); i++){
           alpha[s[i] - '\0']++;
       }
       for(i = 0; i < alpha.size(); i++){
           res += alpha[i] % 2 ? (res % 2 ? alpha[i]-1 : alpha[i]) : alpha[i];
       }
       return res;
    }
};
