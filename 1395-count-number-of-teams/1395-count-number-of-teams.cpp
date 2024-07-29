class Solution {
public:
    int numTeams(vector<int>& rating) {
        
        int n = rating.size();
        int count = 0;

        for(int i=0; i<n; i++){

            int leftsmaller = 0, leftgreater = 0;
            int rightsmaller = 0, rightgreater = 0;

            for(int j=0; j<i ; j++){
                if(rating[j] > rating[i]){
                    leftgreater++;
                }
                if(rating[j] < rating[i]){
                    leftsmaller++;
                }
            }

            for(int j=i+1; j<n ; j++){
                if(rating[j] > rating[i]){
                    rightgreater++;
                }
                if(rating[j] < rating[i]){
                    rightsmaller++;
                }
            }

            count += leftsmaller*rightgreater + leftgreater*rightsmaller;
        }

        return count;
    }
};