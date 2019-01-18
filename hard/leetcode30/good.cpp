class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if(s.empty() || words.empty())
            return {};
        unordered_map<string, int> mp;
        for(int i = 0; i < words.size(); i++)
            mp[words[i]]++;
        vector<int> res;
        int i, q;
        int n = words.size(), len = words[0].size(), m = s.length();
        for(i = 0; i < m - n * len + 1; i++){
            unordered_map<string, int> seen;
            for(q = 0; q < n; q++){
                string tmp = s.substr(i + q * len, len);
                if(mp.find(tmp) != mp.end()){
                    seen[tmp]++;
                    if(seen[tmp] > mp[tmp])
                        break;
                }
                else
                    break;
            }
            if(q == n)
                res.push_back(i);
        }
        return res;
    }
};
