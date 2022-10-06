class Solution {
private:
    string findSlope(vector<int> &p1, vector<int> &p2) {
        
        int x0 = p1.front(), y0 = p1.back();
        int x1 = p2.front(), y1 = p2.back();
        
        int x = x1 - x0;
        int y = y1 - y0;
        
        return to_string(x / __gcd(x, y)) + '$' + to_string(y / __gcd(x, y));
    }
    
public:
    int maxPoints(vector<vector<int>>& points) {
        
        if(points.size() <= 2)
            return points.size();
        
        int maxPoints = 1;
        for(int i = 0; i < points.size(); i++)
        {
            unordered_map<string,int> slopePoints;
            
            for(int j = i + 1; j < points.size(); j++)
                slopePoints[findSlope(points.at(i), points.at(j))]++;
            
            for(auto& [key, val] : slopePoints)
                maxPoints = max(maxPoints, val + 1);
        }
        
        return maxPoints;
    }
};