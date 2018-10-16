class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length())
            return false;
        unordered_map<char, int> chars;
        int dif_count = 0;
        for(int i = 0; i < s.length(); i++){
            chars[s[i]]++;
            chars[t[i]]--;
        }
        for(auto it : chars)
            if(it.second)
                return false;
        return true;
    }
};
