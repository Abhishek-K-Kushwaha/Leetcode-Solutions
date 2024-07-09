class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double total = customers[0][1];
        int n = customers.size();
        int freeat = customers[0][0] + total;
        for (int i = 1; i < n; i++){
            int arv = customers[i][0];
            int t = customers[i][1];
            if (freeat > arv){
                total += (t + freeat - arv);
                freeat += t;
            }
            else{
                total += t;
                freeat = arv + t;
            }
        }
        //double avg = total/n;
        return total/n;
    }
};