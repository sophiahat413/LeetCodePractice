class WordDistance {
vector<string> letters;
public:
    WordDistance(vector<string> words) {
        for(int i = 0; i<words.size(); i++)
            letters.push_back(words[i]);
    }
    
    int shortest(string word1, string word2) {
        map<string, vector<int>> pos;
        pos[word1] = {};
        pos[word2] = {};
        int dis = INT_MAX;
        for(int i = 0; i<letters.size(); i++){
            if(letters[i] == word1){
                pos[word1].push_back(i);
                if(pos[word2].empty())
                    continue;
                else
                    dis = min(dis, i - pos[word2].back());
            }
            else if(letters[i] == word2){
                pos[word2].push_back(i);
                if(pos[word1].empty())
                    continue;
                else
                    dis = min(dis, i - pos[word1].back());
            }
            else
                continue;
        }
        return dis;
    }
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance obj = new WordDistance(words);
 * int param_1 = obj.shortest(word1,word2);
 */
