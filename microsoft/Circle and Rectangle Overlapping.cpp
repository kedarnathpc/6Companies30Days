class Solution {
public:
    bool check(int xn, int yn, int xCenter, int yCenter, int r){
        return (((xn - xCenter)*(xn - xCenter)) + ((yn - yCenter)*(yn - yCenter)) <= r*r);
    }

    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        if(xCenter >= x1 and xCenter <= x2 and yCenter >= y1 and yCenter <= y2)
            return true;
        
        for(int i = x1; i <= x2; ++i)
            if(check(i, y1, xCenter, yCenter, radius) || check(i, y2, xCenter, yCenter, radius))
                return true;
        
        for(int i = y1; i <= y2; ++i)
            if(check(x1, i, xCenter, yCenter, radius) || check(x2, i, xCenter, yCenter, radius))
                return true;
        
        return false;
    }
};