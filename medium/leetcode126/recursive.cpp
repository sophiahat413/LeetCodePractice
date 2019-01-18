class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> res;
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if(!dict.count(endWord))    return {};
        dict.erase(beginWord);
        dict.erase(endWord);
        unordered_map<string, int> steps{{beginWord, 1}};
        unordered_map<string, vector<string>> parents;
        queue<string> Q;
        Q.push(beginWord);
        const int l = beginWord.length();
        int step = 0;
        bool found = false;
        while(!Q.empty() && !found){
            step++;
            int s = Q.size();
            for(int i = 0; i < s; i++){
                string tmp1 = Q.front();
                string tmp2 = tmp1;
                Q.pop();
                for(int q = 0; q < l; q++){
                    char w = tmp1[q];
                    for(char j = 'a'; j <= 'z'; j++){
                        if(j == w)  continue;
                        tmp1[q] = j;
                        if(tmp1 == endWord){
                            parents[endWord].push_back(tmp2);
                            found = true;
                        }
                        else{
                            if(steps.count(tmp1) && steps[tmp1] > step)
                                parents[tmp1].push_back(tmp2);
                        }
                        if(!dict.count(tmp1))   continue;
                        dict.erase(tmp1);
                        Q.push(tmp1);
                        steps[tmp1] = steps[tmp2] + 1;
                        parents[tmp1].push_back(tmp2);
                    }
                    tmp1[q] = w;
                }
            }
        }
        if(found){
            vector<string> curr{endWord};
            getPaths(endWord, beginWord, parents, curr, res);
        }
        return res;
    }
private:
    void getPaths(string& word, string& beginWord, unordered_map<string, vector<string>>& parents, vector<string>& curr, vector<vector<string>>& ans){
        if(word == beginWord){
            ans.push_back(vector<string>(curr.rbegin(), curr.rend()));
            return;
        }
        for(int i = 0; i < parents[word].size(); i++){
            curr.push_back(parents[word][i]);
            getPaths(parents[word][i], beginWord, parents, curr, ans);
            curr.pop_back();
        }
    }
};
