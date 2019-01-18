class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> mpA;
        unordered_map<char, char> mpB;
        for(int i = 0; i < s.length(); i++){
            if(mpA.find(s[i]) == mpA.end()){
                if(mpB.find(t[i]) != mpB.end())
                    return false;
                mpA[s[i]] = t[i];
                mpB[t[i]] = s[i];
            }
            else{
                if(mpA[s[i]] != t[i])
                    return false;
            }
        }
        return true;
    }
};
