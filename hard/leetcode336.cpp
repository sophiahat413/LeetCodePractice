class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        map<string, int> dict;
        vector<vector<int>> res;
        for(int i = 0; i < words.size(); i++){
            string tmp = words[i];
            reverse(tmp.begin(), tmp.end());
            dict[tmp] = i;
        }
        if(dict.find("") != dict.end()){
            for(int i = 0; i < words.size(); i++){
                if(i == dict[""])   continue;
                if(isPalindrome(words[i]))  res.push_back({dict[""], i});
            }
        }
        for(int i = 0; i < words.size(); i++){
            for(int q = 0; q < words[i].size(); q++){
                string l = words[i].substr(0, q);
                string r = words[i].substr(q, words[i].size() - q);
                if(dict.find(l) != dict.end() && isPalindrome(r) && dict[l] != i)
                    res.push_back({i, dict[l]});
                if(dict.find(r) != dict.end() && isPalindrome(l) && dict[r] != i)
                    res.push_back({dict[r], i});
            }
        }
        return res;
    }
    bool isPalindrome(string s){
        int l = 0, r = s.length()-1;
        while(l < r){
            if(s[l++] != s[r--])    return false;
        }
        return true;
    }
};
