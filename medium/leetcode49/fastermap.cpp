class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, multiset<string>> mp;
        int count = 0;
        vector<vector<string>> res;
        for(int i = 0; i < strs.size(); i++){
            string tmp = strs[i];
            sort(tmp.begin(), tmp.end());
            mp[tmp].insert(strs[i]);
        }
        for(auto m : mp){
            vector<string> words(m.second.begin(), m.second.end());
            res.push_back(words);
        }
        return res;
    }
};
