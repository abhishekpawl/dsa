/* https://leetcode.com/problems/word-search/ */
class Solution {
public:
    bool dfs(int i, int j, int pos, int m, int n, vector<vector<char>> &board, string &word) {
        if(pos == word.size()) return true;
        
        if(i < 0 || j < 0 || i >= m || j >= n) return false;
        if(board[i][j] != word[pos]) return false;
        
        char ch = board[i][j];
        board[i][j] = '#';
        bool ans = dfs(i+1, j, pos+1, m, n, board, word)
            or dfs(i, j+1, pos+1, m, n, board, word)
            or dfs(i-1, j, pos+1, m, n, board, word)
            or dfs(i, j-1, pos+1, m, n, board, word);
        board[i][j] = ch;
        return ans;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == word[0])
                    if(dfs(i, j, 0, m, n, board, word)) return true;
            }
        }
        
        return false;
    }
};