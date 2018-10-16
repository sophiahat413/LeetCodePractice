class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length())
            return false;
        int chars[26] = {0};
        for(int i = 0; i < s.length(); i++){
            chars[s[i] - 'a']++;
            chars[t[i] - 'a']--;
        }
        for(int i = 0; i<26; i++)
            if(chars[i])
                return false;
        return true;
    }
};
