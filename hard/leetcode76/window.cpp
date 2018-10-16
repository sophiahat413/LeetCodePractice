
class Solution {
public:
    string minWindow(string s, string t) {
        if(s.empty() || t.empty())
            return "";
        unordered_map<char, int> mp;
        unordered_map<char, int> window;
        int fit = 0, i, len = INT_MAX;
        string res;
        for(i = 0; i < t.length(); i++)
            mp[t[i]]++;
        for(int slow = 0, fast = 0; fast < s.length(); fast++){
            char c = s[fast];
            if(mp.find(c) != mp.end()){
                window[c]++;
                if(window[c] <= mp[c])
                    fit++;
            }
            if(fit >= t.length()){
                while(mp.find(s[slow]) == mp.end() || window[s[slow]] > mp[s[slow]]){
                    window[s[slow]]--;
                    slow++;
                }
                if(fast - slow + 1 < len){
                    len = fast - slow + 1;
                    res = s.substr(slow, len);
                }
            }
        }
        return res;
    }
};
