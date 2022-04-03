class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        priority_queue<int>cards(deck.begin(), deck.end());
        deque<int>q;
        while(!cards.empty()) {
            if(!q.empty()) {
                int temp = q.back();
                q.pop_back();
                q.push_front(temp);
            }
            q.push_front(cards.top());
            cards.pop();
        }
        vector<int>res(q.begin(), q.end());
        return res;
    }
};