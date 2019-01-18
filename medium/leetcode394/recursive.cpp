#include <iostream>
using namespace std;

string decode(string &s, int &cur){
    string res;
    while(cur < s.length() && s[cur] != ']'){
        if(!isdigit(s[cur]))
            res += s[cur++];
        else{
            int n = 0;
            while(cur < s.length() && isdigit(s[cur])){
                n = n * 10 + s[cur] - '0';
                cur++;
            }
            cur++; //'['
            string t = decode(s, cur);
            cur++; //']'
            while(n > 0){
                res += t;
                n--;
            }
        }
    }
    return res;
}
int main(){
    string s1 = "3[a]2[bc]";
    string s2 = "3[a2[c]]";
    string s3 = "2[abc]3[cd]ef";
    int cur = 0;
    cout<<decode(s1, cur)<<endl;
    cur = 0;
    cout<<decode(s2, cur)<<endl;
    cur = 0;
    cout<<decode(s3, cur)<<endl;
    return 0;
}

