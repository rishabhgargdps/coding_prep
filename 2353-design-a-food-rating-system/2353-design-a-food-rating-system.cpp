class FoodRatings {
public:
    struct comp {
        bool operator() (pair<int, string>a, pair<int, string>b) const {
            if(a.first == b.first) return a.second < b.second;
            return a.first > b.first;
        }
    };
    unordered_map<string, set<pair<int, string>, comp>>c_f;
    unordered_map<string, string>f_c;
    unordered_map<string, int>r;
    
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        c_f.clear();
        f_c.clear();
        for(int i=0; i<foods.size(); i++) {
            c_f[cuisines[i]].insert({ratings[i], foods[i]});
            f_c[foods[i]] = cuisines[i];
            r[foods[i]] = ratings[i];
        }
    }
    
    void changeRating(string food, int newRating) {
        string cuisine = f_c[food];
        c_f[cuisine].insert({newRating, food});
        int rating = r[food];
        c_f[cuisine].erase({rating, food});
        r[food] = newRating;
    }
    
    string highestRated(string cuisine) {
        return (*c_f[cuisine].begin()).second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */