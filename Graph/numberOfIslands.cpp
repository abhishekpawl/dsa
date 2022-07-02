/* https://leetcode.com/problems/number-of-islands/ */
class Solution {
public:
    bool isValid(int i, int j, int row, int col) {
        if(i < 0 || j < 0 || i >= row || j >= col) return false;
        return true;
    }
    
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size() == 0) {
            return 0;
        }
        
        int row = grid.size();
        int col = grid[0].size();
        
        vector<vector<bool>> vis(row, vector<bool> (col, false));
        
        int c = 0;
        
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(grid[i][j] == '1') {
                    if(!vis[i][j]) {
                        // BFS
                        c++;
                        queue<pair<int, int>> q;
                        q.push({i, j});
                        //cout<<"("<<i<<","<<j<<"), ";
                        vis[i][j] = true;
                        while(q.size()) {
                            auto x = q.front();
                            q.pop();

                            // +1, 0
                            if(isValid(x.first+1, x.second, row, col))
                                if(!vis[x.first+1][x.second] && grid[x.first+1][x.second] == '1') {
                                    q.push({x.first+1, x.second});
                                    vis[x.first+1][x.second] = true;
                                }

                            // 0, +1
                            if(isValid(x.first, x.second+1, row, col))
                                if(!vis[x.first][x.second+1] && grid[x.first][x.second+1] == '1') {
                                    q.push({x.first, x.second+1});
                                    vis[x.first][x.second+1] = true;
                                }
                            
                            // -1, 0
                            if(isValid(x.first-1, x.second, row, col))
                                if(!vis[x.first-1][x.second] && grid[x.first-1][x.second] == '1') {
                                    q.push({x.first-1, x.second});
                                    vis[x.first-1][x.second] = true;
                                }
                            
                            // 0, -1
                            if(isValid(x.first, x.second-1, row, col))
                                if(!vis[x.first][x.second-1] && grid[x.first][x.second-1] == '1') {
                                    q.push({x.first, x.second-1});
                                    vis[x.first][x.second-1] = true;
                                }
                        }
                    }
                }
            }
        }
        
        return c;
    }
};