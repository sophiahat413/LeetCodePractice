class Solution {
public:
    int char2val(char a){
        switch(a){
            case 'A': return 0;
            case 'C': return 1;
            case 'G': return 2;
            case 'T': return 3;
        }
    }
    vector<string> findRepeatedDnaSequences(string s) {
        if(s.length() < 10)
            return vector<string>();
        vector<string> res;
        // a bit in each set for each possible string
	bitset<1<<20> s1;
        bitset<1<<20> s2;
        int val = 0;
        for(int i = 0; i < 10; i++){
            val = val << 2 | char2val(s[i]);
        }
        s1.set(val);
        int mask = (1 << 20) - 1;
        for(int i = 10; i < s.length(); i++){
            val = (val << 2 & mask) | char2val(s[i]);
            if(s2[val])
                continue;
            if(s1[val]){
                res.push_back(s.substr(i-10+1, 10));
                s2.set(val);
            }
            else
                s1.set(val);
        }
        return res;
    }
};
