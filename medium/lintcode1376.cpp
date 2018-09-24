class Solution {
public:
    /**
     * @param s1: a string
     * @param s2: a string
     * @return: is s1 and s2 are equivalent
     */
    bool isEquivalentStrings(string &s1, string &s2) {
        // Write your code here
        
        if(s1 == s2)
            return true;
        if(s1.length() >= 2){
            string s1a = s1.substr(0, s1.length()/2);
            string s1b = s1.substr(s1.length()/2);
            string s2a = s2.substr(0, s2.length()/2);
            string s2b = s2.substr(s2.length()/2);
            if((isEquivalentStrings(s1a, s2b) && isEquivalentStrings(s1b, s2a)) || (isEquivalentStrings(s1a, s2a) && isEquivalentStrings(s1b, s2b)))
                return true;
        }
        return false;
    }
};
