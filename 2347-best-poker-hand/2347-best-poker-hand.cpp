class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        unordered_map<int, int>rank;
        unordered_map<char, int>suit;
        for(int i=0; i<5; i++) {
            rank[ranks[i]]++;
            suit[suits[i]]++;
        }
        for(auto itr=suit.begin(); itr!= suit.end(); ++itr) {
            if(itr->second == 5) return "Flush";
        }
        for(auto itr=rank.begin(); itr!= rank.end(); ++itr) {
            if(itr->second >= 3) return "Three of a Kind";
        }
        for(auto itr=rank.begin(); itr!= rank.end(); ++itr) {
            if(itr->second == 2) return "Pair";
        }
        return "High Card";
    }
};