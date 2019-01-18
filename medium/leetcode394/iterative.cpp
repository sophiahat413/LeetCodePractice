#include <iostream>
#include <stack>
using namespace std;

string decode(string s){
    stack<string> st_string;
    stack<int> st_num;
    string cur_string;
    int cur_num = 0;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == '['){
            st_string.push(cur_string);
            st_num.push(cur_num);
            cur_string = "";
            cur_num = 0;
        }
        else if(isdigit(s[i])){
            cur_num = cur_num * 10 + s[i] - '0';
        }
        else if(s[i] == ']'){
            string pre_string = st_string.top();
            int pre_num = st_num.top();
            st_string.pop();
            st_num.pop();
            while(pre_num > 0){
                pre_string += cur_string;
                pre_num--;
            }
            cur_string = pre_string;
        }
        else
            cur_string += s[i];
    }
    return cur_string;
}
int main(){
    string s1 = "3[a]2[bc]";
    string s2 = "3[a2[c]]";
    string s3 = "2[abc]3[cd]ef";
    cout<<decode(s1)<<endl;
    cout<<decode(s2)<<endl;
    cout<<decode(s3)<<endl;
    return 0;
}

