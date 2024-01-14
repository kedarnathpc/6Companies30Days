class Solution {
public:
    bool isValidSerialization(string preorder) {
        int node = 1;
        
        for(int i=0; i<preorder.size(); ++i){
            if(preorder[i] == ',')
                continue;
            
            node--;

            while(i < preorder.size() and preorder[i]>='0' and preorder[i]<='9' and preorder[i]!=',')
                i++;
            
            if(node < 0)
                return false;

            if(preorder[i] != '#')
                node += 2;
        }

        return node == 0;
    }
};