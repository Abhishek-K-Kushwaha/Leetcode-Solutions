class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses);
        for (auto edge:prerequisites){
            adj[edge[1]].push_back(edge[0]);
            indegree[edge[0]]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++){
            if (indegree[i] == 0){
                q.push(i);
            }
        }
        vector<int> ans;
        int cnt = 0;
        while (!q.empty()){
            int node = q.front();
            q.pop();
            for (auto nxt:adj[node]){
                indegree[nxt]--;
                if (indegree[nxt] == 0) q.push(nxt);
            }
            ans.push_back(node);
            cnt++;
        }
        if (cnt == numCourses) return ans;
        else return {};    
    }
};