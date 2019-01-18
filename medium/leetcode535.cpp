class Solution {
private:
    map<string, string> code_url, url_code;
    const string dict = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string code = "";
        if(!url_code.count(longUrl)){
            for(int i = 0; i < 6; i++){
                code.push_back(dict[random() % dict.size()]);
            }
            url_code.insert(pair<string, string>(longUrl, code));
            code_url.insert(pair<string, string>(code, longUrl));
        }
        else
            code = url_code[longUrl];
        return "http://tinyurl.com/" + code;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        if(shortUrl.length() != 25 || !code_url.count(shortUrl.substr(19, 6)))
            return "";
        return code_url[shortUrl.substr(19, 6)];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
