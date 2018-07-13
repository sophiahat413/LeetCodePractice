class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<vector<char>> array;
        int max_length = 0, index = 0;
        for(int i = 0; i< s.length(); i++){
            unordered_map<char, int> hash;
            vector<char> ans;
            ans.push_back(s[i]);
            hash[s[i]] = 1;
            for(int q = i+1; q< s.length(); q++){
                if(hash.find(s[q]) != hash.end()){
                    array.push_back(ans);
                    break;       
                }
                else{
                    ans.push_back(s[q]);
                    hash[s[q]] = 1;
                }
            }
            array.push_back(ans);
        }
        for(int i = 0; i<array.size(); i++){
            if(array[i].size() >= max_length){
                max_length = array[i].size();
            }
        }
        return max_length;
    }
};
