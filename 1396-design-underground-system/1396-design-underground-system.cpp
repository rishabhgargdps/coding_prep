class UndergroundSystem {
public:
    map<pair<string, string>, pair<int, int>>time;
    map<int, pair<string, int>>start;
    
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        start[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        string startStation = start[id].first;
        int startTime = start[id].second;
        int prev_total = time[{startStation, stationName}].first;
        int prev_num = time[{startStation, stationName}].second;
        time[{startStation, stationName}] = {prev_total + t - startTime, prev_num+1};
    }
    
    double getAverageTime(string startStation, string endStation) {
        return (double)time[{startStation, endStation}].first/time[{startStation, endStation}].second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */