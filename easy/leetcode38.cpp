class Solution {
public:
    string countAndSay(int n) {
        string old, real;
        if(n == 1)
            return "1";
        int p1, i, q, count = 0;
        for(i = 0; i < n; i++){
            string ans;
            if(i == 0)
                ans = "1";
            else{
                for(q = 0; q<old.length(); q++){
                    if(old[q] == old[q+1]){
                        count = 1;
                        while(old[q] == old[q+1]){
                            count++;
                            q++;
                        }
                        ans.append(1, count+'0');
                        ans.append(1, old[q]);
                    }
                    else{
                        ans.append("1");
                        ans.append(1, old[q]);
                    }
                }
            }
            old = ans;
            real = ans;
        }
        return real;
    }
};
