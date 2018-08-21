//take cosey's code as reference
class Solution {
    public:
    string reverse(string s){
        string rev;
        for(int i = s.length()-1; i>=0; i--){
            rev += s[i];
        }
        return rev;
    }
    string longestPalindrome(string s) {
        string rev = reverse(s);
        int table[s.length()+1][rev.length()+1];
        int i,q, max = 0, x = 0,y = 0;
        string pali;
        for(i = 0; i<=s.length(); i++)
            for(q = 0; q<=rev.length(); q++)
                table[i][q] = 0;
        for(i = 1; i<=s.length(); i++){
            for(q = 1; q<=rev.length(); q++){
                if(s[i-1] == rev[q-1]){
                    table[i][q] = table[i-1][q-1] + 1; 
                    if(table[i][q] > max){
                        if(i- table[i][q] != s.length()-q)
                            continue;
                        max = table[i][q];
                        x = i;
                        y = q;
                    }
                }
            }
        }
        string ans;
        for(i = max, q = x - max; i > 0; i--, q++ )
            ans += s[q];
        return ans;
    }
};




