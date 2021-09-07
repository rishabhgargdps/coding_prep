class Solution
{
public:
    bool isRectangleOverlap(vector<int> &rec1, vector<int> &rec2)
    {
        //top edge compare
        if (rec1[3] > rec2[3])
        {
            if (rec1[1] >= rec2[3])
                return false;
        }
        else if (rec1[3] < rec2[3])
        {
            if (rec2[1] >= rec1[3])
                return false;
        }
        //left edge compare
        if (rec1[0] < rec2[0])
        {
            if (rec1[2] <= rec2[0])
                return false;
        }
        else if (rec1[0] > rec2[0])
        {
            if (rec2[2] <= rec1[0])
                return false;
        }
        return true;
    }
};