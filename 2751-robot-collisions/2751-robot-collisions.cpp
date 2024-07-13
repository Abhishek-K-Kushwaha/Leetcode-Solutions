class Solution {
public:
        vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<pair<int, int>> robots;
        for (int i = 0; i < n; ++i) {
            robots.push_back({positions[i], i});
        }
        sort(robots.begin(), robots.end());

        stack<int> stk; // stack to store the indices of robots
        for (auto& robot : robots) {
            int ind = robot.second;
            if (directions[ind] == 'R') {
                stk.push(ind);
            } else {
                while (!stk.empty() && healths[ind] > 0) {
                    int topIndex = stk.top();

                    if (healths[topIndex] == healths[ind]) {
                        healths[topIndex] = 0;
                        healths[ind] = 0;
                        stk.pop();
                    } else if (healths[topIndex] > healths[ind]) {
                        healths[topIndex]--;
                        healths[ind] = 0;
                    } else {
                        healths[ind]--;
                        healths[topIndex] = 0;
                        stk.pop();
                    }
                }
            }
        }

        vector<int> result;
        for (int h : healths) {
            if (h > 0) result.push_back(h);
        }

        return result;
    }
};