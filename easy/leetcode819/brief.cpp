class Solution {
public:
    
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_map<string, int> map;
        for(int i = 0; i<paragraph.length();){
            string s = "";
            while(i < paragraph.length() && isalpha(paragraph[i])) 
                s += tolower(paragraph[i++]);
            while(i < paragraph.length() && !isalpha(paragraph[i]))
                i++;
            map[s] ++;
        }
        for(auto x: banned)
            map[x] = 0;
        int max = 0;
        string result;
        for(auto w: map){
            if(w.second > max){
                max = w.second;
                result = w.first;
            }
        }
        return result;
    }
};
