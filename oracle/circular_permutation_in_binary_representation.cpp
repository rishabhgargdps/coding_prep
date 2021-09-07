class Solution
{
public:
    vector<int> circularPermutation(int n, int start)
    {
        vector<int> gray_code;
        int total = 1 << n;
        for (int i = 0; i < total; i++)
        {
            gray_code.push_back(i ^ (i >> 1));
        }
        vector<int> res;
        int start_index = 0;
        for (int i = 0; i < gray_code.size(); i++)
        {
            if (gray_code[i] == start)
            {
                start_index = i;
                break;
            };
        }
        int i = start_index;
        do
        {
            res.push_back(gray_code[i]);
            i = (i + 1) % gray_code.size();
        } while (i != start_index);
        return res;
    }
};