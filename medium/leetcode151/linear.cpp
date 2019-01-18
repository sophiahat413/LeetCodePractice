class Solution {
public:
    void reverseWords(string &s) {
        string res;
        int pos = 0;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == ' '){
                if(i > pos)
                    res = s.substr(pos, i-pos) + " " + res;
                pos = i+1;
            }
            else if(i == s.length()-1)
                res = s.substr(pos, s.size()-pos) + " "+ res;
        }
        s = res.substr(0, res.size()-1);
    }
};
