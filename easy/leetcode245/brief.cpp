class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        long long dist = INT_MAX;
        long long indexA = dist, indexB = -dist;
        for(int i = 0; i < words.size(); i++){
            if(words[i] == word1)
                indexA = i;
            if(words[i] == word2){
                if(word1 == word2)
                    indexA = indexB;
                indexB = i;
            }
            dist = min(dist, abs(indexA - indexB));
        }
        return dist;
    }
};
