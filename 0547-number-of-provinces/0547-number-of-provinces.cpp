class Solution {
public:
    void dfs(int node, int n, vector<int>& visited, vector<vector<int>>& isConnected){
        visited[node] = 1;
        for (int j = 0; j < n; j++){
            if (j != node && isConnected[node][j] == 1 && !visited[j]){
                dfs(j, n, visited, isConnected);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> visited(n);
        int count = 0;
        for (int i = 0; i < n; i++){
            if (!visited[i]){
                count++;
                dfs(i, n, visited, isConnected);
            }
        }
        return count;
    }
};