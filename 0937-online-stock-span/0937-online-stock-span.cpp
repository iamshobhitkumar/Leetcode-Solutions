class StockSpanner {
public:
    vector<int> v;
    StockSpanner() {
        v.resize(0);
    }
    
    int next(int price) {
        v.push_back(price);
        int i=v.size()-2, count =1;
        while(i>=0 && v[i--]<= price) count++;
        return count;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */