class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(beginWord == endWord)
            return 1;
        int n = beginWord.length();
        if(n < 1 || n != endWord.length())
            return 0;
        unordered_set<string> dict;
        for(int i = 0; i < wordList.size(); i++)
            dict.insert(wordList[i]);
        int length = 2, qL;
        string tmp;
        queue<string> q;
        q.push(beginWord);
        dict.erase(beginWord);
        while(!q.empty()){
            qL = q.size();
            for(int k = 0; k < qL; k++){
                string word = q.front();
                q.pop();
                for(int i = 0; i<n; i++){
                    char oldChar = word[i];
                    for(char c = 'a'; c <= 'z'; c++){
                        if(c == oldChar)
                            continue;
                        word[i] = c;
                        if(dict.find(word) != dict.end()){
                            if(word == endWord)
                                return length;
                            q.push(word);
                            dict.erase(word);
                        }
                    }
                    word[i] = oldChar;
                }
            }
            length++;
        }
        return 0;
    }
};
