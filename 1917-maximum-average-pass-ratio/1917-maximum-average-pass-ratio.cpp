class Solution {
public:
    double f(int a, int b) {
        return (double)(a + 1) / (b + 1) - (double)a / b;
    }

    double maxAverageRatio(vector<vector<int>>& classes, int ext) {
        priority_queue<pair<double, double>> pq;
        int n = classes.size();
        int ind = 0;
        for (auto it:classes){
            pq.push({f(it[0], it[1]), (double)ind});
            ind++;
        }
        for (int i = 0; i < ext; i++){
            auto it = pq.top();
            pq.pop();
            ind = it.second;
            classes[ind][0]++; classes[ind][1]++;
            pq.push({f(classes[ind][0],classes[ind][1]),(double)ind});
        }
        double ans = 0;
        for (auto it: classes){
            ans += ((double)it[0]/it[1]);
        }
        return ans/n;
    }
};