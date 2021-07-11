//wrong answer

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int merge_intervals(vector<vector<int>> &intervals)
{
    vector<int> prev = intervals[0];
    int count = 1;
    int max_count = 1;
    for (auto interval : intervals)
    {
        max_count = max(max_count, count);
        if (prev[1] > interval[0])
        {
            prev[1] = max(prev[1], interval[1]);
            count++;
        }
        else
        {
            count = 1;
            prev = interval;
        }
    }
    return max_count;
}

//correct ans

bool Solution::hotel(vector<int> &arrive, vector<int> &depart, int K)
{
    vector<vector<int>> arr;
    for (int i = 0; i < arrive.size(); i++)
    {
        arr.push_back({arrive[i], depart[i]});
    }
    return merge_intervals(arr) <= K;
}

bool Solution::hotel(vector<int> &arrive, vector<int> &depart, int K)
{
    vector<pair<int, int>> v;
    for (int i = 0; i < arrive.size(); i++)
    {
        v.push_back({arrive[i], 1});
    }
    for (int i = 0; i < arrive.size(); i++)
    {
        v.push_back({depart[i], 0});
    }
    int count = 0;
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i].second == 1)
            count++;
        else
            count--;
        if (count > K)
            return 0;
    }
    return 1;
}
