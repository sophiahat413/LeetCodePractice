class Solution {
public:
   vector<int> findPermutation(string s) {
        vector<int> res(1, 1);
        auto b = res.begin();
        int q = 2;
        for(int i = 0; i < s.length(); i++){
            //cout<<i<<endl;
            if(s[i] == 'D'){
                b = res.insert(b, q);
                q++;
            }
            else if(s[i] == 'I'){
                res.push_back(q);
                q++;
                b = prev(res.end());
            }
        }
        return res;
    }
  
};
