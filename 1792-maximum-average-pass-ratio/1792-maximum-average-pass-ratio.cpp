class Solution {
public:
    double f(double a, double b){
        double ans = ((a+1)/(b+1)-(a/b));
        return ans;
    }
    double maxAverageRatio(vector<vector<int>>& classes, int ext) {
        priority_queue<vector<double>> pq;
        int n = classes.size();
        for (auto it:classes){
            pq.push({f(it[0], it[1]), (double)it[0], (double)it[1]});
        }
        // while (!pq.empty()){
        //     auto it = pq.top();
        //     pq.pop();
        //     cout<< it[0] << " " <<it[1]<<" "<<it[2]<<endl;
        //     //ans += (it[1]/it[2]);
        // }
        for (int i = 0; i < ext; i++){
            auto it = pq.top();
            pq.pop();
            double num = it[1] + 1;
            double deno = it[2] + 1;
            pq.push({f(num,deno), num, deno});
        }
        double ans = 0;
        while (!pq.empty()){
            auto it = pq.top();
            pq.pop();
            ans += (it[1]/it[2]);
        }
        return ans/n;
    }
};