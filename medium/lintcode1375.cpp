class Solution {
public:
    /**
     * @param s: a string
     * @param k: an integer
     * @return: the number of substrings there are that contain at least k distinct characters
     */
    long long kDistinctCharacters(string &s, int k) {
        // Write your code here
       //set<string> isExist;
       long long res = 0;
       int i = 0, count, n = s.length();
       while(i < s.length()){
           string line;
           map<char, int> lookup;
           lookup[s[i]] = 1;
           line += s[i];
           count = 1;
           if(count >= k)
            res++;
           for(int q = i+1; q < s.length(); q++){
                line += s[q];
                if(lookup.find(s[q]) == lookup.end()){
                    lookup[s[q]] = 1;
                    count++;
                }
                if(count >= k){
                    res = res + (n - q);
                    break;
                }
           }
           i++;
           if((n - i) < k)
            break;
       }
       return res;
    }
};
