class Solution
{
public:
    int compare(string word1, string word2, vector<int> &char_map)
    {
        int i = 0;
        int j = 0;
        int compare_char = 0;
        while (i < word1.length() && j < word2.length() && compare_char == 0)
        {
            compare_char = char_map[word1[i] - 'a'] - char_map[word2[j] - 'a'];
            i++;
            j++;
        }
        if (compare_char == 0)
            return word1.length() - word2.length();
        return compare_char;
    }

    bool isAlienSorted(vector<string> &words, string order)
    {
        vector<int> char_map(26);
        for (int i = 0; i < order.length(); i++)
        {
            char_map[order[i] - 'a'] = i;
        }
        for (int i = 1; i < words.size(); i++)
        {
            if (compare(words[i - 1], words[i], char_map) > 0)
                return false;
        }
        return true;
    }
};