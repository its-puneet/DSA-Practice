class Solution {
private:
    
    int dirX[4] = {0, 1, 0,-1};
    int dirY[4] = {1, 0,-1, 0};
    
    bool stringPossible(int i, int j, int &n, int &m, int index, string &word,
                        vector<vector<bool>> &vis, vector<vector<char>> &board) {
        
        if(index >= word.length() - 1)
            return index == word.length() - 1;
        
        index++;
        vis[i][j] = true;
        
        bool isPossible = false;
        for(int k = 0; k < 4; k++)
        {
            int y = i + dirY[k];
            int x = j + dirX[k];
            
            if(y < 0 || x < 0 || y > n || x > m || vis[y][x] || board[y][x] != word.at(index))
                continue;
            
            isPossible |= stringPossible(y, x, n, m, index, word, vis, board);
        }
        
        vis[i][j] = false;
        index--;
        
        return isPossible;
    }
    
public:
    bool exist(vector<vector<char>>& board, string word) {
        
        int n = board.size() - 1, m = board[0].size() - 1;
        
        vector<pair<int,int>> candidates;
        for(int i = 0; i <= n; i++)
            for(int j = 0; j <= m; j++)
                if(board[i][j] == word.front())
                    candidates.emplace_back(make_pair(i, j));
        
        vector<vector<bool>> vis(n+1, vector<bool>(m+1, false));
        int index = 0;
        
        for(pair<int,int> &candidate : candidates)
            if(stringPossible(candidate.first, candidate.second, n, m, index, word, vis, board))
                return true;
        return false;
    }
};