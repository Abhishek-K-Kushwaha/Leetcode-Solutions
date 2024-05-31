class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int prevcolor = image[sr][sc];
        if (prevcolor == color)
            return image;
        int m = image.size();
        int n = image[0].size();
        vector<vector<int>> modimg = image;
        queue<vector<int>> q;
        q.push({sr, sc});
        while (!q.empty()) {
            vector<int> cord = q.front();
            q.pop();
            int r = cord[0];
            int c = cord[1];
            modimg[r][c] = color;

            if (r - 1 >= 0 && modimg[r - 1][c] == prevcolor) {
                q.push({r - 1, c});
            }
            if (r + 1 < m && modimg[r + 1][c] == prevcolor) {
                q.push({r + 1, c});
            }
            if (c - 1 >= 0 && modimg[r][c - 1] == prevcolor) {
                q.push({r, c - 1});
            }
            if (c + 1 < n && modimg[r][c + 1] == prevcolor) {
                q.push({r, c + 1});
            }
        }
        return modimg;
    }
};