class Solution {
public:
    
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_map<string, int> map;
        unordered_map<string, int> bann;
        int MAX = INT_MIN;
        string maxW;
        for(int i = 0; i<banned.size(); i++){
            cout<<banned[i]<<endl;
            bann[banned[i]] = 1;
        }
        string word;
        for(int i = 0; i< paragraph.length(); i++){
            if((paragraph[i]<'a' || paragraph[i]>'z') && (paragraph[i]<'A' || paragraph[i]>'Z')) {
                if(word.length()){
                    if(map.find(word) != map.end())
                        map[word] ++;
                    else
                        map[word] = 1;
                    if(bann.find(word) == bann.end()){
                        if(map[word] > MAX){
                            MAX = map[word];
                            maxW = word;
                        }
                    }
                    word = "";
                }
                else
                    continue;
            }
            else{
                word += tolower(paragraph[i]);
                if(i == paragraph.size()-1){
                    if(map.find(word) != map.end())
                        map[word] ++;
                    else
                        map[word] = 1;
                    if(bann.find(word) == bann.end()){
                        if(map[word] > MAX){
                            MAX = map[word];
                            maxW = word;
                        }
                    }
                }
            }
        }
        return maxW;
    }
};
