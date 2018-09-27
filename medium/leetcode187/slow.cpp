class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        map<string, int> seq;
        vector<string> res;
        for(int i = 0; i < s.length(); i++){
            string tmp = s.substr(i, 10);
            if(seq.find(tmp) == seq.end())
                seq[tmp] = 1;
            else
                seq[tmp]++;
            if(seq[tmp] == 2)
                res.push_back(tmp);
        }
        return res;
    }
};
