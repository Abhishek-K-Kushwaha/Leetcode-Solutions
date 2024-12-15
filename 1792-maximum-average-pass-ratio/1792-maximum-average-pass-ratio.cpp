class Solution {
public:
    double f(int a, int b) {
        return (double)(a + 1) / (b + 1) - (double)a / b;
    }

    double maxAverageRatio(vector<vector<int>>& classes, int ext) {
        // Max heap to store {improvement, index}
        auto cmp = [](const pair<double, int>& a, const pair<double, int>& b) {
            return a.first < b.first; // Max heap
        };
        priority_queue<pair<double, int>, vector<pair<double, int>>, decltype(cmp)> pq(cmp);

        // Initialize the priority queue with the improvements
        for (int i = 0; i < classes.size(); ++i) {
            pq.push({f(classes[i][0], classes[i][1]), i});
        }

        // Allocate extra students
        for (int i = 0; i < ext; ++i) {
            auto [maxImprovement, idx] = pq.top();
            pq.pop();

            // Increment the class stats
            classes[idx][0]++;
            classes[idx][1]++;

            // Push the updated improvement back to the heap
            pq.push({f(classes[idx][0], classes[idx][1]), idx});
        }

        // Calculate the final average ratio
        double totalRatio = 0.0;
        for (const auto& cls : classes) {
            totalRatio += (double)cls[0] / cls[1];
        }

        return totalRatio / classes.size();
    }
};