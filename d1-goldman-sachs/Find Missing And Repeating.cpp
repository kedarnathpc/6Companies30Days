class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        // code here
        int rep, miss;
        
        for(int i=0; i<n; i++){
            if(arr[abs(arr[i])-1] < 0){
                rep = abs(arr[i]);
            } else{
                arr[abs(arr[i])-1] *= -1;  
            }
        }
        
        for(int i=0; i<n; i++){
            if(arr[i] > 0){
                miss = i+1;
                break;
            }
        }
        
        return {rep, miss};
    }
};