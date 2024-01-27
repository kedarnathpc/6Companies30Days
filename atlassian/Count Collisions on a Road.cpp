class Solution {
public:
    int countCollisions(string directions) {
        int collisionCount = 0;
        stack<char> dirStack;
        int Right_way = 0;

        for (auto dir : directions) {
            
            if(dir == 'R') Right_way++;
            bool noRoute = false; 
            
            if (dirStack.empty()) dirStack.push(dir); 
    
            else if (dirStack.top() == 'S' && dir == 'L') collisionCount++; 

            else if (dirStack.top() == 'R' && dir == 'L') {
                collisionCount += 2 ; dirStack.pop(); 
                noRoute = true;Right_way--;
            }
            else dirStack.push(dir);
            
            if (noRoute || dir == 'S') {
               collisionCount += (Right_way); 
               Right_way = 0;
               dirStack.push('S'); 
            }
        }
        
        return collisionCount; // Return the total collision count
    }
};