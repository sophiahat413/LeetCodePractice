class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        int idx = 0;
        while(idx < words.size()){
            int end = idx;
            int total = 0;
            vector<string> line;
            //get the current line
            while(end < words.size() && total+line.size()+words[end].length() <= maxWidth){
                line.push_back(words[end]);
                total += words[end].length();
                end++;
            }
            string l = words[idx];
            //the last line or just the single word ->left alignment
            //just pad the space to the end
            if(end == words.size() || line.size() == 1){
                for(int i = idx+1; i < end; i++){
                    l += " " + words[i];
                }
                l += string(maxWidth - (total+line.size()-1), ' ');
            }
            else{
                int space_len = maxWidth - total;
                int left = space_len % (line.size()-1);
                int base = space_len / (line.size()-1);
                int cnt = 0;
                for(int i = idx+1; i < end; i++){
                    l += string(base, ' ');
                    if(cnt < left){
                        l += " ";
                        cnt++;
                    }
                    l += words[i];
                }
            }
            res.push_back(l);
            idx = end;
        }
        return res;
    }
};
