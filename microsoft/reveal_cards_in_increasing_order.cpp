class Solution
{
public:
    vector<int> deckRevealedIncreasing(vector<int> &deck)
    {
        priority_queue<int> maxHeap(deck.begin(), deck.end());
        deque<int> q;
        while (!maxHeap.empty())
        {
            int num = maxHeap.top();
            maxHeap.pop();
            if (!q.empty())
            {
                int temp = q.back();
                q.pop_back();
                q.push_front(temp);
            }
            q.push_front(num);
        }
        vector<int> res(q.begin(), q.end());
        return res;
    }
};