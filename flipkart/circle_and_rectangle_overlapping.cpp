class Solution
{
public:
    bool checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2)
    {
        int x = x_center;
        int y = y_center;
        if (x_center < x1)
            x_center = x1;
        else if (x_center > x2)
            x_center = x2;
        if (y_center < y1)
            y_center = y1;
        else if (y_center > y2)
            y_center = y2;
        int X_dist = x - x_center;
        int Y_dist = y - y_center;
        return X_dist * X_dist + Y_dist * Y_dist <= radius * radius;
    }
};