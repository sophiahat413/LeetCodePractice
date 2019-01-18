class Solution {
public:
    string findReplaceString(string S, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
        string original = S, res = "";
        int n = S.length();
        vector<string> pos(n);
        for(int i = 0; i < n; i++){
            pos[i] = string(1, S[i]);
        }
        for(int i = 0; i < indexes.size(); i++){
            int sta = indexes[i];
            int cnt = 0, tmp = sta, len = sources[i].length();
            if(S.substr(tmp, len) == sources[i]){
                for(int q = sta+1; q <= tmp+len-1; q++)
                    pos[q] = "";
                pos[sta] = targets[i];
            }
        }
        for(int i = 0; i < pos.size(); i++){
            res += pos[i];
        }
        return res;
    }
};
