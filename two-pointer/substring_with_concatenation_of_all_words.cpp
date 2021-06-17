//wrong solution
class Solution
{
public:
    vector<int> findSubstring(string s, vector<string> &words)
    {
        unordered_map<string, int> m;
        for (string s : words)
        {
            m[s]++;
        }
        int word_count = words.size();
        int word_length = words[0].length();
        vector<int> res;
        int begin = 0;
        int end = 0;
        for (end = 0; end < s.length(); end += word_length)
        {
            if (m.find(s.substr(end, word_length)) != m.end() && m[s.substr(end, word_length)] > 0)
            {
                word_count--;
                m[s.substr(end, word_length)]--;
            }
            else
            {
                end++;
                word_count = words.size();
                while (begin <= end)
                {
                    m[s.substr(begin, word_length)]++;
                    begin += word_count;
                }
                begin = end;
            }
            if (word_count == 0)
            {
                res.push_back(begin);
                m[s.substr(begin, word_length)]++;
                begin += word_count;
                word_count++;
            }
        }
        return res;
    }
};

//correct solution
class Solution
{
public:
    vector<int> findSubstring(string s, vector<string> &words)
    {
        unordered_map<string, int> m;
        for (string s : words)
        {
            m[s]++;
        }
        int word_count = words.size();
        int word_length = words[0].length();
        vector<int> res;
        int end = 0;
        for (end = 0; end < s.length() - word_count * word_length + 1; end++)
        {
            unordered_map<string, int> freq;
            for (int j = 0; j < word_count; j++)
            {
                int word_index = end + j * word_length;
                string word = s.substr(word_index, word_length);
                cout << word;
                if (m.find(word) == m.end())
                    break;
                freq[word]++;
                if (freq[word] > m[word])
                    break;
                // cout << word;
                if (j + 1 == word_count)
                    res.push_back(end);
            }
        }
        return res;
    }
};