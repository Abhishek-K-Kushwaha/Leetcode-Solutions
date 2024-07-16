class StockSpanner {
public:
    stack<pair<int,int>> stk; // {price, span}
    StockSpanner() {
        stk.push({0,0});
    }
    
    int next(int price) {
        int ans = 1;
        // if (price >= stk.top().first){
            while (!stk.empty() && price >= stk.top().first){
                ans += stk.top().second;
                stk.pop();
            }
            // stk.push({price,ans});
            // return ans;
        ///}
        //else{
            stk.push({price, ans});
            return ans;
        //}
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */