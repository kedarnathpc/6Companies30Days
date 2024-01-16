class Solution {
public:
    int longestString(int x, int y, int z) {
        return ((min(x, y) + min(x, y) + (x != y) + z) * 2);
    }
};