class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int res = 0;
        int dict[256];
        fill_n(dict,256,0);
        int cnt = 0;
        for(int slow = 0, fast = 0; fast < s.length(); fast++){
            dict[s[fast]]++;
            if(dict[s[fast]] == 1){
                cnt++;
                while(cnt > 2){
                    dict[s[slow]]--;
                    if(dict[s[slow]] == 0)
                        cnt--;
                    slow++;
                }
            }
            res = max(res, fast-slow+1);
        }
        return res;
    }
};
