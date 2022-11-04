class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        
        set<vector<int>> obstacleCells(obstacles.cbegin(), obstacles.cend());
        
        int x = 0, y = 0, p = 0,
            dirX[4] = {0, 1, 0,-1},
            dirY[4] = {1, 0,-1, 0};
        
        int maxLen = 0;
        for(int &c : commands)
        {
            switch(c)
            {
                case -1 :
                    p = (p + 1) % 4;
                    break;
                case -2 :
                    p = (p + 3) % 4;
                    break;
                default:
                    while(c--)
                    {
                        if(obstacleCells.find(vector<int>({x + dirX[p], y + dirY[p]})) != obstacleCells.end())
                            break;
                        x += dirX[p], y += dirY[p];
                    }
                    maxLen = max(maxLen, x * x + y * y);
            }
        }
        
        return maxLen;
        
    }
};