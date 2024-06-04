class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> visited(n,-1);
        queue<int> q;
        for (int i = 0; i < n; i++){
            if (visited[i] == -1){
                q.push(i);
                visited[i] = 0;
                while (!q.empty()){
                    int node = q.front();
                    int color = visited[node];
                    q.pop();
                    for (int nxt:graph[node]){
                        if (visited[nxt] == -1){
                            if (color){
                                visited[nxt] = 0;
                            }
                            else{
                                visited[nxt] = 1;
                            }
                            q.push(nxt);
                        }
                        else if (visited[nxt] == color) return false;
                    }
                }
            }
        }
        return true;
    }
};