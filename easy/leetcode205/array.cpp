class Solution {
public:
    bool isIsomorphic(string s, string t) {
        char charArrs[256] = {0};
        char charArrt[256] = {0};
        for(int i = 0; i < s.length(); i++){
            if(charArrs[s[i]] == 0 && charArrt[t[i]] == 0){
                charArrs[s[i]] = t[i];
                charArrt[t[i]] = s[i];
            }
            else{
                if(charArrs[s[i]] != t[i] || charArrt[t[i]] != s[i])
                    return false;
            }
        }
        return true;
    }
};
