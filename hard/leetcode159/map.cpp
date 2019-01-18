class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int res = 0;
        unordered_map<char, int> dict;
        int cnt = 0;
        for(int slow = 0, fast = 0; fast < s.length(); fast++){
            if(dict.find(s[fast]) == dict.end()){
                dict[s[fast]]++;
                cnt++;
            }
            else
                dict[s[fast]]++;
            if(cnt <= 2){
                res = max(res, fast-slow + 1);
                continue;
            }
            else if(cnt > 2){
                while(slow < fast){
                    dict[s[slow]]--;
                    if(dict[s[slow]] == 0){
                        dict.erase(s[slow]);
                        cnt--;
                        slow++;
                        res = max(res, fast-slow + 1);
                        break;
                    }
                    slow++;
                }
            }
        }
        return res;
    }
};
