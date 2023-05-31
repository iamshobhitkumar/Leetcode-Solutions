class UndergroundSystem {
public:
    unordered_map<int, pair<int,string>> m;
    unordered_map<string, pair<double,int>> m1;
    UndergroundSystem() {
        m.clear();
        m1.clear();
    }
    
    void checkIn(int id, string stationName, int t) {
        if(m.find(id) == m.end()){
            m[id] = {t, stationName};
        }
    }
    
    void checkOut(int id, string stationName, int t) {
        if(m.find(id)!=m.end()){
            m1[m[id].second + '_' + stationName].first += t-m[id].first;
            m1[m[id].second + '_' + stationName].second +=1;
            m.erase(id);

        }
    }
    
    double getAverageTime(string startStation, string endStation) {
        string temp = startStation + '_' + endStation;
        return m1[temp].first / m1[temp].second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */