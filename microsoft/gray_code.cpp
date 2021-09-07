//fastest solution
class Solution
{
public:
    int binaryToGray(uint n)
    {
        return n ^ (n >> 1);
    }

    vector<int> grayCode(int n)
    {
        vector<int> res;
        uint size = (1 << n);
        res.reserve(size);
        for (uint i = 0; i < size; i++)
        {
            res.push_back(binaryToGray(i));
        }
        return res;
    }
};

//invalid code
class Solution
{
public:
    vector<int> grayCode(int n)
    {
        vector<int> res;
        uint16_t num = 0;
        uint16_t mask = 0;
        res.push_back(num);
        int temp = n;
        while (temp--)
        {
            mask = mask << 1;
            mask += 1;
        }
        temp = n;
        while (temp--)
        {
            num += 1;
            res.push_back(num & mask);
            num = num << 1;
        }
        temp = n;
        num = num >> 1;
        while (temp--)
        {
            num = num << 1;
            res.push_back(num & mask);
            // bitset<16>x(num & mask);
            // cout << x << endl;
        }
        res.pop_back();
        return res;
    }
};