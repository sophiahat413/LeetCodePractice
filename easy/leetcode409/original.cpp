class Solution {
    public:
    int longestPalindrome(string s) {
       if(s == "")
            return 0;
       unordered_map<char, int> hash;
       int i, count = 0, length = 0, max = 0, flag = 0;
       vector<int> letters;
       for(i = 0; i<s.length(); i++){
           if(hash.find(s[i]) != hash.end())
               letters[hash[s[i]]]++;
           else{
                hash[s[i]] = count;
                letters.push_back(1);
                count++;
           }
       }
       for(i = 0; i<letters.size(); i++){
           if(letters[i] % 2 == 0){
                length += letters[i];
           }
           else{
                flag = 1;
                length += letters[i]-1;
           }
       }
       if(flag)
        return length+1;
       return length;
    }
};
