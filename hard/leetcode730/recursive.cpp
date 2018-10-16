class Solution {
private:
    long count(const string& S){
        if(S.empty())   return 0;
        if(S.length() == 1) return 1;
        auto it = mp.find(S);
        if(it != mp.end())  return it->second;
        const int n = S.length();
        long ans = 0;
        if(S[0] == S[n-1]){
            int l = 1, r = n-2;
            while(l <= r && S[l] != S[0])   l++;
            while(l <= r && S[r] != S[0])   r--;
            if(l > r)
                ans = count(S.substr(1, n-2)) * 2 + 2;
            else if(l == r)
                ans = count(S.substr(1, n-2)) * 2 + 1;
            else
                ans = count(S.substr(1, n-2)) * 2 - count(S.substr(l+1, r-l-1));
        }
        else{
            ans = count(S.substr(0, n-1)) + count(S.substr(1, n-1)) - count(S.substr(1, n-2));
        }
        return mp[S] = (ans + mod) % mod;
    }
    static constexpr long mod = 1000000007;
    unordered_map<string, long> mp;
public:
    int countPalindromicSubsequences(string S) {
        return count(S);
    }
};
