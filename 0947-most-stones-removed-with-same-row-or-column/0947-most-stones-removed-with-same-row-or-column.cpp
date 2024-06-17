class DisjointSet {
public:
    vector<int> sizevec, parent;
    DisjointSet(int n) {
        sizevec.resize(n + 1, 1);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findp(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findp(parent[node]);
    }

    void unionBySize(int u, int v) {
        int paru = findp(u);
        int parv = findp(v);
        if (paru == parv)
            return;
        if (sizevec[paru] < sizevec[parv]) {
            parent[paru] = parv;
            sizevec[parv] += sizevec[paru];
        } else {
            parent[parv] = paru;
            sizevec[paru] += sizevec[parv];
        }
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int maxrow = 0;
        int maxcol = 0;
        int numstones = 0;
        for (auto it : stones) {
            numstones++;
            if (it[0] > maxrow)
                maxrow = it[0];
            if (it[1] > maxcol)
                maxcol = it[1];
        }
        DisjointSet ds(maxrow + 1 + maxcol + 1);
        for (auto it : stones) {
            int u = it[0];
            int v = it[1] + maxrow + 1;
            ds.unionBySize(u, v);
        }
        int components = 0;
        for (int sz : ds.sizevec) {
            if (sz > 1)
                components++;
        }
        return numstones - components;
    }
};