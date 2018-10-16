class Solution {
public:
    int countSubstrings(string s) {
        int res = 0, n = s.length();
        for(int i = 0; i < n; i++){
           for(int j = 0; i - j >= 0 && i + j < n && s[i+j] == s[i-j] ; j++)
               res++;
           for(int j = 0; i - j - 1 >= 0 && i + j < n && s[i+j] == s[i-j - 1] ; j++)
               res++;
        }
        return res;
    }
};
