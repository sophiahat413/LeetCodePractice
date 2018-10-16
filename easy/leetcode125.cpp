class Solution {
public:
    /**
     * @param s: A string
     * @return: Whether the string is a valid palindrome
     */
    bool isPalindrome(string &s) {
        // write your code here
        int l = 0, r = s.length()-1, flag = 0;
        for(int l = 0, r = s.length()-1; l < r; l++, r--){
            while(!isalnum(s[l]) && l < r)  l++;
            while(!isalnum(s[r]) && l < r)  r--;
            if(tolower(s[l]) != tolower(s[r]))  return false;
        }
        return true;
    }
};
