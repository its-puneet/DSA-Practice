class Solution {
private:
    vector<vector<bool>> findOceanCells(string ocean, int &m, int &n, vector<vector<int>> &heights) {
       
	   int dirX[4] = {0, 1, 0,-1}, dirY[4] = {1, 0,-1, 0};
        
        vector<vector<bool>> oceanCells(m + 1, vector<bool>(n + 1, false));
        queue<pair<int,int>> q;
        
        for(int i = 0, j = (!ocean.compare("pacific") ? 0 : n); i <= m; i++)
        {
            oceanCells[i][j] = true;
            q.emplace(make_pair(i, j));
        } 
        for(int i = (!ocean.compare("pacific") ? 0 : m), j = 0; j <= n; j++)
        {
            oceanCells[i][j] = true;
            q.emplace(make_pair(i, j));
        }          
        
        while(!q.empty())
        {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            
            for(int k = 0; k < 4; k++)
            {
                int y = i + dirY[k];
                int x = j + dirX[k];
                
                if(y < 0 || x < 0 || y > m || x > n || oceanCells[y][x] || heights[y][x] < heights[i][j])
                    continue;
                oceanCells[y][x] = true;
                q.emplace(make_pair(y, x));
            }
        }
        
        return oceanCells;
    }
    
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        
        int m = heights.size() - 1, n = heights[0].size() - 1;
        
        // Pacific Ocean calculation
        vector<vector<bool>> pacificCells = findOceanCells("pacific", m, n, heights);
        
        // Atlantic Ocean calculation
        vector<vector<bool>> atlanticCells = findOceanCells("atlantic", m, n, heights);
        
        // Cells will indicate ocean coverage
        vector<vector<int>> cells;
        for(int i = 0; i <= m; i++)
            for(int j = 0; j <= n; j++)
                if(pacificCells[i][j] & atlanticCells[i][j])
                    cells.emplace_back(vector<int>({i, j}));
        
        return cells;
        
    }
};