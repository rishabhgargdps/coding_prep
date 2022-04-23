class Solution {
public:
    unordered_map<string, string>m;
    int num = 0;
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        num++;
        m["http://tinyurl.com/"+to_string(num)] = longUrl;
        return "http://tinyurl.com/"+to_string(num);
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return m["http://tinyurl.com/"+to_string(num)];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));