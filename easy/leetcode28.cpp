class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.length() == 0)
            return 0;
        if(haystack.length() < needle.length())
            return -1;
        int index = -1;
        int i = 0,j = 0, k = 0;
        while(i <= haystack.length()-1){
            if(haystack[j] == needle[k]){
                if(i == j)
                    index = i;
                j++;
                k++;
                if(k== needle.length())
                    break;
            }
            else{
                index = -1;
                i++;
                k = 0;
                j = i;
                continue;
            }   
        }
        return index;
    }
};
