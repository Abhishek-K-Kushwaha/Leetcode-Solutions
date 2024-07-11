class Solution {
public:
    int twoEggDrop(int n) {
        int num = sqrt(n);
        while (true) {
            if (num * (num - 1) / 2 >= n)
                return num - 1;
            num++;
        }
        return -1;
    }
};