class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length())
            return false;
        map<char, int> chars;
        int dif_count = 0;
        for(int i = 0; i < s.length(); i++){
            if(chars.find(s[i]) == chars.end()){
                chars[s[i]] = 1;
                dif_count++;
            }
            else
                chars[s[i]] ++;
        }
        for(int i = 0; i < t.length(); i++){
            if(chars.find(t[i]) == chars.end())
                return false;
            else{
                chars[t[i]]--;
                if(chars[t[i]] == 0)
                    chars.erase(t[i]);
            }
        }
        return true;
    }
};
