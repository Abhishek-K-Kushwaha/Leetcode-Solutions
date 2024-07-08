class Solution {
public:
    int findTheWinner(int n, int k) {
        int numFriends = n;
        vector<int> friends(n, 1);
        int cnt = 0;
        int ptr = 1;
        while (n != 1){
            if (friends[ptr]){
                if (++cnt == k){
                    friends[ptr] = 0;
                    n--;
                    cnt = 0;
                }
            }
            ptr = (ptr + 1) % numFriends;
        }
        for (int i = 0; i < numFriends; i++){
            if (friends[i]){
                if (i == 0) return numFriends;
                else return i;
            }
        }
        return -1;
    }
};