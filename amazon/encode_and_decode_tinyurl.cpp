class Solution
{
public:
    unordered_map<string, string> m;
    int num = 0;
    // Encodes a URL to a shortened URL.
    string encode(string longUrl)
    {
        num++;
        string last = to_string(num);
        m["http://tinyurl.com/" + num] = longUrl;
        return "http://tinyurl.com/" + num;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl)
    {
        return m["http://tinyurl.com/" + num];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));