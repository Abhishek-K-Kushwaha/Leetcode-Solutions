class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(n==1) return 1;

        unordered_map<int, int> indegree, outdegree;

        for(auto i: trust){
            int trusts = i[0];
            int trusted = i[1];

            indegree[trusted]++;
            outdegree[trusts]++;
        }

        for(auto i: indegree){
            int node = i.first;
            int in = i.second;
            if(in == n-1 && outdegree[node]==0) 
                return node;
        }

        return -1;
    }
};