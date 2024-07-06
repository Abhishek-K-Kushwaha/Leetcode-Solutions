class Solution {
public:
    int passThePillow(int n, int time) {
        int ind = time % (n-1);
        if (time % (2*(n-1)) == ind){
            return 1 + ind;
        }
        else return n - ind;
    }
};