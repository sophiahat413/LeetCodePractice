class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, int> pos;
        int count = 0;
        vector<vector<string>> res;
        for(int i = 0; i < strs.size(); i++){
            string tmp = strs[i];
            sort(tmp.begin(), tmp.end());
            cout<<tmp<<endl;
            if(pos.find(tmp) == pos.end()){
                vector<string> word;
                pos[tmp] = count;
                word.push_back(strs[i]);
                res.push_back(word);
                count++;
            }
            else{
                res[pos[tmp]].push_back(strs[i]);
            }
        }
        return res;
    }
};
