class Solution {
public:
    double f(int a, int b) {
        return (double)(a + 1) / (b + 1) - (double)a / b;
    }
    
    double maxAverageRatio(vector<vector<int>>& classes, int ext) {
        priority_queue<vector<double>> pq;
        int n = classes.size();
        int ind = 0;
        for (auto it:classes){
            pq.push({f(it[0], it[1]), (double)ind});
            ind++;
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
            ind = it[1];
            //double deno = it[2] + 1;
            classes[ind][0]++; classes[ind][1]++;
            pq.push({f(classes[ind][0],classes[ind][1]),(double)ind});
        }
        double ans = 0;
        // while (!pq.empty()){
        //     auto it = pq.top();
        //     pq.pop();
        //     ans += (it[1]/it[2]);
        // }
        for (auto it: classes){
            ans += ((double)it[0]/it[1]);
        }
        return ans/n;
    }
};