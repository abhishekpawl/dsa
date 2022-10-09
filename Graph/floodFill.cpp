/* https://practice.geeksforgeeks.org/problems/flood-fill-algorithm1856/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=flood-fill-algorithm */
class Solution {
public:
    bool check(int r, int c, int nr, int nc) {
        if(r < 0 || c < 0 || r >= nr || c >= nc) return false;
        return true;
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int old = image[sr][sc];
        int nr = image.size();
        int nc = image[0].size();
        vector<vector<bool>> vis(nr, vector<bool> (nc));
        queue<pair<int, int>> q;
        q.push({sr, sc});
        vis[sr][sc] = true;
        vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while(!q.empty()) {
            auto x = q.front();
            q.pop();
            int r = x.first;
            int c = x.second;
            image[r][c] = newColor;
            for(int i = 0; i < 4; i++) {
                if(check(r+dir[i][0], c+dir[i][1], nr, nc) && vis[r+dir[i][0]][c+dir[i][1]] == false && image[r+dir[i][0]][c+dir[i][1]] == old) {
                    q.push({r+dir[i][0], c+dir[i][1]});
                    vis[r+dir[i][0]][c+dir[i][1]] = true;
                }
            }
        }
        return image;
    }
};