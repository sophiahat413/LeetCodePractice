class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        if(strs.size() == 0)
            return "";
        else if(strs.size() == 1)
            return strs[0];
        else{
            int length = 0, count = 0;
            string prefix = strs[0];
            for(int i = 1; i<strs.size(); i++){
                count = 0;
                for(int q = 0; q< min(strs[0].length(), strs[i].length()); q++){
                    if(strs[0][0] != strs[i][0])
                        return "";
                    if(strs[0][q] != strs[i][q])
                        break;
                    else
                        count++;
                }
                prefix.erase(prefix.begin()+count, prefix.end());
            }
            return prefix;
        }
    }
};
