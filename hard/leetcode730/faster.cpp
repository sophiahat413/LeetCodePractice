class Solution {
private:
    long count(const string& S, int s, int e){
        if(s > e)   return 0;
        if(s == e)  return 1;
        const int key = s * S.length() + e;
        if(mp[key] > 0) return mp[key];
        long ans = 0;
        if(S[s] == S[e]){
            int l = s+1, r = e-1;
            while(l <= r && S[l] != S[s])   l++;
            while(l <= r && S[r] != S[s])   r--;
            if(l > r)
                ans = count(S, s+1, e-1) * 2 + 2;
            else if(l == r)
                ans = count(S, s+1, e-1) * 2 + 1;
            else
                ans = count(S, s+1, e-1) * 2 - count(S, l+1, r-1);
        }
        else{
            ans = count(S, s, e-1) + count(S, s+1, e) - count(S, s+1, e-1);
        }
        return mp[key] = (ans + mod) % mod;
    }
    static constexpr long mod = 1000000007;
    vector<int> mp;
public:
    int countPalindromicSubsequences(string S) {
        const int n = S.length();
        mp = vector<int>(n * (n+1) + 1, 0);
        return count(S, 0, S.length()-1);
    }
};
